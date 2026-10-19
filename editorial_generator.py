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
        description="Strictly follows LeetCode canonical markdown: # Intuition, # Approach, # Complexity, # Code with ```cpp [] containing clean uncommented code.",
    )
    selected_tag_slugs: List[str] = Field(
        ...,
        description="Array of 2 to 4 valid tag slugs from allowed_tags, always including 'c'",
    )
    github_cpp_file: str = Field(
        ...,
        description="Complete standalone C++ file with top header comment, #include <bits/stdc++.h>, using namespace std, and clean uncommented solution code.",
    )
    github_readme_markdown: str = Field(
        ...,
        description="Formatted GitHub README with title link, difficulty, tags, converted problem markdown, and editorial.",
    )


SYSTEM_PROMPT = """You are a Principal Software Engineer and Grandmaster Competitive Programmer specializing in modern C++20 and Data Structures & Algorithms.
Your task is to analyze a LeetCode problem statement, its metadata, and the user's accepted C++ submission, then generate a structured JSON payload containing:
1. A high-signal LeetCode Community Solution article designed for maximum readability, upvotes, and reach.
2. Clean, completely uncommented C++ source code with necessary local headers for a GitHub repository.
3. A comprehensive GitHub README.md containing the problem statement and your editorial.

### VIRAL QUALITY & HIGH-REACH GUIDELINES:
- **Title Formula for Maximum Reach**:
  Format: '<Approach Name> | O(<Time>) Time, O(<Space>) Space | C++20 Clean Solution'.
  Prepend 'Beats <X>% | ' ONLY if runtime_percentile >= 90.0 (e.g. 'Beats 100% | O(N) One Pass Hash Table | C++20 Clean Solution').
- **Fidelity to User Code**:
  Base your explanation strictly on the exact algorithm, data structures, and technique used in the provided user code. Do NOT invent a different approach. Ground every step in the actual variable and function names from the user code.
- **Visual Dry Run / Trace Walkthrough**:
  Under `# Approach`, in addition to numbered steps, include a clean ASCII diagram or state walkthrough table showing variable values across iterations for Example 1. LeetCode readers overwhelmingly upvote posts with concrete visual traces.
- **Rigorous Complexity Proof**:
  Derive the exact Time and Space Complexity in standard LaTeX ($$O(...)$$). Explicitly justify loops, auxiliary containers, recursion stacks, and sorting overhead.
- **Clean Code Without Commentary Clutter**:
  CRITICAL: Do NOT add inline comments inside the C++ code. Keep the code completely clean, concise, elegant, and readable without inline commentary. The explanation belongs in the Markdown editorial sections (# Intuition, # Approach, # Complexity), NOT inside the code.
- **Tone & Style**:
  Concise, technical, direct, and authoritative. Zero conversational filler, no greetings, no introductory fluff, no emojis in the technical breakdown.

### OUTPUT FORMAT REQUIREMENTS:
Return ONLY a valid JSON object matching the requested schema:
- "lc_post_title": High-signal title string as specified above.
- "lc_post_markdown": Strictly LeetCode canonical structure:
# Intuition
(2-3 punchy sentences explaining the core observation or mathematical invariant that makes this approach work)

# Approach
(1. Numbered step-by-step breakdown referencing actual variable names from user code)
(2. Include a visual trace walkthrough or ASCII state diagram of Example 1)
(3. Mention corner-case handling, e.g. empty bounds, duplicates, or overflow prevention)

# Complexity
- Time complexity: $$O(...)$$ — step-by-step justification of operations and iterations.
- Space complexity: $$O(...)$$ — justification distinguishing auxiliary data structures vs call stack.

# Code
```cpp []
<user code with ZERO inline comments>
```
- "selected_tag_slugs": Array of 2 to 4 valid tag slugs from allowed_tags list, always containing 'c'.
- "github_cpp_file": Complete standalone C++ file containing:
  1. Top header comment block with Problem Title, Link, Difficulty, Time/Space Complexity.
  2. '#include <bits/stdc++.h>' and 'using namespace std;'
  3. The user's exact clean code with ZERO inline comments.
- "github_readme_markdown": Clean Markdown formatted README:
  # [<FrontendId>. <Title>](https://leetcode.com/problems/<titleSlug>/)
  **Difficulty:** <Difficulty> | **Tags:** <Comma-separated tags>

  ---

  ## Problem Description
  <Clean Markdown conversion of problem HTML, preserving examples and constraints>

  ---

  ## Solution & Editorial
  <Include Intuition, Approach with Visual Walkthrough, and Complexity sections here>
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

    # Clean and extract the user's authentic accepted C++ code
    user_code = details.get("code", "").strip()

    # Guarantee # Code is ALWAYS cleanly present in LeetCode Community Markdown
    # Extract only the editorial sections before any # Code
    if "# Code" in output.lc_post_markdown:
        editorial_body = output.lc_post_markdown.split("# Code")[0].strip()
    else:
        editorial_body = output.lc_post_markdown.strip()

    output.lc_post_markdown = f"{editorial_body}\n\n# Code\n```cpp []\n{user_code}\n```\n"

    # Guarantee standalone clean C++ source code with standard headers and NO inline comment clutter
    header_comment = f"""/**
 * Problem: {q.get('title', '')} ({q.get('questionFrontendId', '')})
 * Link: https://leetcode.com/problems/{q.get('titleSlug', '')}/
 * Difficulty: {q.get('difficulty', '')}
 */

#include <bits/stdc++.h>
using namespace std;

"""
    output.github_cpp_file = f"{header_comment}{user_code}\n"

    # Guarantee GitHub README has description, editorial, and exact code
    display_tags = ", ".join(f"`{t}`" for t in allowed_tags[1:]) if len(allowed_tags) > 1 else "`Algorithm`"
    output.github_readme_markdown = f"""# [{q.get('questionFrontendId', '')}. {q.get('title', '')}](https://leetcode.com/problems/{q.get('titleSlug', '')}/)
**Difficulty:** `{q.get('difficulty', '')}` | **Tags:** {display_tags}

---

## Problem Description
{clean_problem_text}

---

## Solution & Editorial
{editorial_body}

# Code
```cpp
{user_code}
```
"""

    return output
