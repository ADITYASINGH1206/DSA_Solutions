# [2114. Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
A **sentence** is a list of **words** that are separated by a single space with no leading or trailing spaces.

You are given an array of strings `sentences`, where each `sentences[i]` represents a single **sentence**.

Return *the **maximum number of words** that appear in a single sentence*.

**Example 1:**

```
Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
```

**Example 2:**

```
Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
Explanation: It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
```

**Constraints:**

* `1 <= sentences.length <= 100`
* `1 <= sentences[i].length <= 100`
* `sentences[i]` consists only of lowercase English letters and `' '` only.
* `sentences[i]` does not have leading or trailing spaces.
* All the words in `sentences[i]` are separated by a single space.

---

## Solution & Editorial
# Intuition
Since each sentence consists of words separated by exactly one space, the number of words in a sentence is always equal to the number of spaces plus one. We can iterate through each sentence, count the occurrences of the space character, and track the global maximum.

# Approach
1. Initialize a variable `max_words` to 0 to store the result.
2. Iterate through each string `s` in the `sentences` vector.
3. For each sentence, count the number of spaces by iterating through the characters of the string. Let this count be `space_count`.
4. The number of words in the current sentence is `space_count + 1`.
5. Update `max_words` using `std::max(max_words, space_count + 1)`.
6. Return `max_words` after processing all sentences.

### Visual Trace (Example 1)
`sentences = ["alice and bob", "i think"]`

| Sentence | Spaces | Words (Spaces + 1) | max_words |
| :--- | :--- | :--- | :--- |
| "alice and bob" | 2 | 3 | 3 |
| "i think" | 1 | 2 | 3 |

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ is the number of sentences and $$M$$ is the maximum length of a sentence. We visit every character in every sentence exactly once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    return Math.max(...sentences.map(s => s.split(" ").length)) 
};
```
