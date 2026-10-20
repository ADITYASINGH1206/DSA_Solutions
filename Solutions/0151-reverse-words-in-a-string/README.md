# [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)
**Difficulty:** `Medium` | **Tags:** `two-pointers`, `string`

---

## Problem Description
Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space.*

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Example 1:**

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**Constraints:**

* `1 <= s.length <= 104`
* `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
* There is **at least one** word in `s`.

**Follow-up:**If the string data type is mutable in your language, can you solve it **in-place** with `O(1)` extra space?

---

## Solution & Editorial
# Intuition
The problem requires us to reverse the order of words in a string while removing leading, trailing, and duplicate spaces. By scanning the string backwards from right to left, we can naturally extract words in reverse order and append them directly to our collection, handling multiple spaces seamlessly.

# Code
```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> s1;
        int n = s.size();
        int i = n - 1;
        
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) break; 
            string temp = "";
            while(i >= 0 && s[i] != ' '){
                temp += s[i];
                i--;
            }
            reverse(temp.begin(), temp.end());
            s1.push_back(temp);
        }
        
        for(int j = 0; j < s1.size(); j++){
            ans += s1[j];
            if(j != s1.size() - 1) ans += ' ';
        }
        
        return ans;
    }
};
```
