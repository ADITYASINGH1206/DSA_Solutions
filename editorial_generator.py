import json
import re
from typing import Dict, Any, List
from pydantic import BaseModel, Field
import markdownify
from google import genai
from google.genai import types

from config import GEMINI_API_KEY, GEMINI_MODEL


class SolutionOutput(BaseModel):
    lc_post_title: str = Field(
        ...,
        description="Format: '<Approach Name> | O(<Time>) Time, O(<Space>) Space | C++ Clean Solution'. Prepend 'Beats <X>% | ' ONLY if runtime_percentile >= 90.",
    )
    lc_post_markdown: str = Field(
        ...,
        description="Strictly follows LeetCode canonical markdown: # Intuition, # Approach, # Complexity, # Code with ```cpp []",
    )
    selected_tag_slugs: List[str] = Field(
        ...,
        description="Array of 2 to 4 valid tag slugs from allowed_tags, always including 'c'",
    )
    github_cpp_file: str = Field(
        ...,
        description="Complete standalone C++ file with top header comment, #include <bits/stdc++.h>, using namespace std, and commented solution code.",
    )
    github_readme_markdown: str = Field(
        ...,
        description="Formatted GitHub README with title link, difficulty, tags, converted problem markdown, and editorial.",
    )


SYSTEM_PROMPT = """You are an expert Competitive Programmer and Staff Software Engineer specializing in C++20 and Data Structures & Algorithms.
Your task is to analyze a LeetCode problem statement, its metadata, and the user's accepted C++ submission, then generate a structured JSON payload containing:
1. A high-signal LeetCode Community Solution article.
2. Clean, inline-commented C++ source code with necessary local headers for a GitHub repository.
3. A comprehensive GitHub README.md containing the problem statement and your editorial.

### STRICT GUIDELINES FOR ALGORITHMIC ANALYSIS:
- **Fidelity to User Code**: Base your explanation STRICTLY on the exact algorithm, data structures, and trick used in the provided user code. Do NOT invent an alternative "optimal" approach if the user's code uses a different method (e.g., if the user used Memoization, do not write the explanation for Tabulation).
- **Variable Grounding**: Reference the exact variable and function names present in the user's C++ code when walking through the step-by-step logic.
- **Exact Complexity Analysis**: Derive the exact Time and Space Complexity of the user's specific implementation. Account for recursion call stacks, auxiliary containers, and sorting overhead. Use standard LaTeX notation ($O(N \\log N)$).
- **Tone & Style**: Concise, technical, and direct. Zero conversational filler, no "Hello fellow coders", and no emojis in the technical breakdown.

### OUTPUT FORMAT REQUIREMENTS:
Return ONLY a valid JSON object matching the requested schema:
- "lc_post_title": '<Approach Name> | O(<Time>) Time, O(<Space>) Space | C++ Clean Solution'. Prepend 'Beats <X>% | ' ONLY if runtime_percentile >= 90.
- "lc_post_markdown": Strictly LeetCode canonical structure:
# Intuition
(2-3 sentences on the core observation)

# Approach
(Numbered step-by-step breakdown referencing actual variable names from user code)

# Complexity
- Time complexity: $$O(...)$$ — brief justification.
- Space complexity: $$O(...)$$ — brief justification.

# Code
```cpp []
<user code with brief inline comments explaining non-obvious lines>
```
- "selected_tag_slugs": Array of 2 to 4 valid tag slugs from allowed_tags list, always containing 'c'.
- "github_cpp_file": Complete standalone C++ file containing:
  1. Top header comment block with Problem Title, Link, Difficulty, Time/Space Complexity.
  2. '#include <bits/stdc++.h>' and 'using namespace std;'
  3. The user's exact code with concise inline comments explaining non-obvious lines.
- "github_readme_markdown": Clean Markdown formatted README:
  # [<FrontendId>. <Title>](https://leetcode.com/problems/<titleSlug>/)
  **Difficulty:** <Difficulty> | **Tags:** <Comma-separated tags>

  ---

  ## Problem Description
  <Clean Markdown conversion of problem HTML, preserving examples and constraints>

  ---

  ## Solution & Editorial
  <Include Intuition, Approach, and Complexity sections here>
"""


def clean_html_to_markdown(html_content: str) -> str:
    """
    Convert raw LeetCode HTML problem statement into clean, readable GitHub markdown.
    """
    if not html_content:
        return ""
    md = markdownify.markdownify(html_content, heading_style="ATX", strip=["img"])
    # Clean up excessive newlines
    md = re.sub(r"\n{3,}", "\n\n", md)
    return md.strip()


def generate_artifacts(details: Dict[str, Any]) -> SolutionOutput:
    """
    Single-shot LLM generator using Gemini 2.5 Flash and Structured Outputs.
    """
    if not GEMINI_API_KEY:
        raise ValueError("GEMINI_API_KEY is not set. Please add it to your .env file.")

    client = genai.Client(api_key=GEMINI_API_KEY)
    q = details.get("question", {})
    topic_tags = q.get("topicTags", []) or []
    tag_slugs = [t["slug"] for t in topic_tags if "slug" in t]
    allowed_tags = ["c"] + tag_slugs

    runtime = details.get("runtime", 0)
    runtime_percentile = details.get("runtimePercentile")
    if runtime_percentile is None:
        runtime_percentile = 0.0

    memory = details.get("memory", 0)
    memory_percentile = details.get("memoryPercentile")
    if memory_percentile is None:
        memory_percentile = 0.0

    raw_html = q.get("content", "")
    clean_problem_text = clean_html_to_markdown(raw_html)

    user_prompt = f"""### PROBLEM METADATA
- ID: {q.get('questionFrontendId', '')}
- Title: {q.get('title', '')}
- Slug: {q.get('titleSlug', '')}
- Difficulty: {q.get('difficulty', '')}
- Allowed Tag Slugs: {json.dumps(allowed_tags)}

### SUBMISSION TELEMETRY
- Language: C++
- Runtime: {runtime} ms (Beats {runtime_percentile:.1f}%)
- Memory: {memory} MB (Beats {memory_percentile:.1f}%)

### PROBLEM STATEMENT (CLEAN MARKDOWN)
{clean_problem_text}

### RAW PROBLEM STATEMENT (HTML)
```html
{raw_html}
```

### USER'S ACCEPTED C++ CODE
```cpp
{details.get('code', '')}
```
"""

    response = client.models.generate_content(
        model=GEMINI_MODEL,
        contents=user_prompt,
        config=types.GenerateContentConfig(
            system_instruction=SYSTEM_PROMPT,
            response_mime_type="application/json",
            response_schema=SolutionOutput,
            temperature=0.2,
        ),
    )

    result_text = response.text
    if not result_text:
        raise RuntimeError("LLM returned empty response")

    output = SolutionOutput.model_validate_json(result_text)

    # Ensure 'c' is in selected tag slugs
    if "c" not in output.selected_tag_slugs:
        output.selected_tag_slugs.insert(0, "c")

    return output
