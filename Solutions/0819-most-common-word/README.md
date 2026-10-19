# [819. Most Common Word](https://leetcode.com/problems/most-common-word/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `counting`

---

## Problem Description
Given a string `paragraph` and a string array of the banned words `banned`, return *the most frequent word that is not banned*. It is **guaranteed** there is **at least one word** that is not banned, and that the answer is **unique**.

The words in `paragraph` are **case-insensitive** and the answer should be returned in **lowercase**.

**Note** that words can not contain punctuation symbols.

**Example 1:**

```
Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
```

**Example 2:**

```
Input: paragraph = "a.", banned = []
Output: "a"
```

**Constraints:**

* `1 <= paragraph.length <= 1000`
* paragraph consists of English letters, space `' '`, or one of the symbols: `"!?',;."`.
* `0 <= banned.length <= 100`
* `1 <= banned[i].length <= 10`
* `banned[i]` consists of only lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires extracting words from a paragraph, ignoring punctuation, converting characters to lowercase, filtering out any banned words, and finding the most frequent remaining word. A hash set (`std::set`) provides efficient $O(\log K)$ lookup for banned words, while a hash map (`std::unordered_map`) accumulates frequencies for valid words in $O(1)$ average time per word.

# Approach
1. Initialize a `std::set<string>` named `st` from the `banned` vector to achieve fast $O(\log K)$ lookups.
2. Initialize an empty string `word` and an `std::unordered_map<string, int> mp` to record word frequencies.
3. Iterate through every character `c` in the `paragraph` string:
   - If `c` is an alphabetic character via `isalpha(c)`, convert it to lowercase using `tolower(c)` and append it to `word`.
   - If `c` is not alphabetic (such as a space or punctuation symbol), check if `word` is non-empty and not present in `st`. If valid, increment its count in `mp`. Finally, clear `word` for the next token.
4. Perform a final check after the loop to capture any trailing word that does not end with a non-alphabetic delimiter.
5. Iterate through the frequency map `mp` to find the string with the maximum frequency (`maxi`) and return it as `ans`.

### Visual Trace Walkthrough (Example 1)
Paragraph: `"Bob hit a ball"`, Banned: `["hit"]`

| Character `c` | Action on `word` | `st.find(word)` | `mp` State | Remarks |
| :--- | :--- | :--- | :--- | :--- |
| `'B'` | `word = "b"` | - | - | Lowercased |
| `'o'` | `word = "bo"` | - | - | - |
| `'b'` | `word = "bob"` | Not found | `{"bob": 1}` | Space encountered, added |
| `'h'` | `word = "h"` | - | - | - |
| `'i'` | `word = "hi"` | - | - | - |
| `'t'` | `word = "hit"` | Found in `st` | `{"bob": 1}` | Banned, skipped |
| `'a'` | `word = "a"` | Not found | `{"bob": 1, "a": 1}` | Space encountered, added |
| `'b'` | `word = "b"` | - | - | - |
| `'a'` | `word = "ba"` | - | - | - |
| `'l'` | `word = "bal"` | - | - | - |
| `'l'` | `word = "ball"` | Not found | `{"bob": 1, "a": 1, "ball": 1}` | End of string, added |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the length of the paragraph and $$M$$ is the total number of characters in the banned words list. Inserting banned words into `st` takes $$O(M \log K)$$ where $$K$$ is the number of banned words. Parsing the paragraph of length $$N$$ and updating the hash map takes linear time relative to the paragraph length.
- Space complexity: $$O(N + M)$$ to store the banned words in the set and record unique words along with their frequencies in the hash map.

# Code
```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> mp;
        set<string> st(banned.begin(),banned.end());
        string word = "";
        for(char c:paragraph){
            if(isalpha(c)) word+= tolower(c);
            else{
                if(!word.empty() && st.find(word) == st.end()) mp[word]++;
                word.clear();
            }
        }

        if(!word.empty() && st.find(word) == st.end()) mp[word]++;
        
        int maxi = 0;
        string ans = "";
        for(auto it:mp){
            if(it.second > maxi){
                ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};
```
