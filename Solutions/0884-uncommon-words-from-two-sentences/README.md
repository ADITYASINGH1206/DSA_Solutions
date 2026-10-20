# [884. Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
A **sentence** is a string of single-space separated words where each word consists only of lowercase letters.

A word is **uncommon** if it appears exactly once in one of the sentences, and **does not appear** in the other sentence.

Given two **sentences** `s1` and `s2`, return *a list of all the **uncommon words***. You may return the answer in **any order**.

**Example 1:**

**Input:** s1 = "this apple is sweet", s2 = "this apple is sour"

**Output:** ["sweet","sour"]

**Explanation:**

The word `"sweet"` appears only in `s1`, while the word `"sour"` appears only in `s2`.

**Example 2:**

**Input:** s1 = "apple apple", s2 = "banana"

**Output:** ["banana"]

**Constraints:**

* `1 <= s1.length, s2.length <= 200`
* `s1` and `s2` consist of lowercase English letters and spaces.
* `s1` and `s2` do not have leading or trailing spaces.
* All the words in `s1` and `s2` are separated by a single space.

---

## Solution & Editorial
# Intuition
An uncommon word is defined as a word that appears exactly once across both sentences combined. By utilizing a hash map to tally the frequencies of every word from both `s1` and `s2`, we can identify all unique terms in linear time.

# Approach
1. Initialize an `unordered_map<string, int> mp` to store word counts and a string `temp` to extract words token by token.
2. Iterate through each character in `s1`. When a space `' '` is encountered, increment the frequency of `temp` in `mp` and reset `temp`. After the loop finishes, record the final word remaining in `temp`.
3. Repeat the exact same parsing process for `s2`, continuing to accumulate word frequencies into the same hash map `mp`.
4. Iterate through all key-value pairs in `mp`. If a word's frequency `value` equals `1`, append the `key` to the result vector `ans`.
5. Return `ans`.

### Visual Walkthrough (Example 1)
Input: `s1 = "this apple is sweet"`, `s2 = "this apple is sour"`

| Action | `temp` | Hash Map State (`mp`) |
| :--- | :--- | :--- |
| Parse `s1` | "sweet" | `{"this": 2, "apple": 2, "is": 2, "sweet": 1}` |
| Parse `s2` | "sour" | `{"this": 2, "apple": 2, "is": 2, "sweet": 1, "sour": 1}` |
| Filter `mp` | - | Collect keys where frequency == 1: `["sweet", "sour"]` |

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ and $$M$$ are the lengths of `s1` and `s2` respectively. Extracting words and inserting them into the hash map takes linear time relative to the string lengths, and iterating over the unique words takes time proportional to the number of distinct words.
- Space complexity: $$O(N + M)$$ to store the unique words and their frequencies in the `unordered_map` and the resulting answer vector.

# Code
```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        vector<string> ans;
        string temp = "";
        for(char c: s1){
            if(c == ' ') {
                mp[temp]++;
                temp = "";
            }else{
                temp += c;
            }
        }
        mp[temp]++;
        temp = "";
        for(char c: s2){
            if(c == ' ') {
                mp[temp]++;
                temp = "";
            }else{
                temp += c;
            }
        }
        mp[temp]++;
        for(auto [key,value] : mp){
            if (value == 1){
                ans.push_back(key);
            }
        }
        return ans;


    }
};
```
