# [748. Shortest Completing Word](https://leetcode.com/problems/shortest-completing-word/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`

---

## Problem Description
Given a string `licensePlate` and an array of strings `words`, find the **shortest completing** word in `words`.

A **completing** word is a word that **contains all the letters** in `licensePlate`. **Ignore numbers and spaces** in `licensePlate`, and treat letters as **case insensitive**. If a letter appears more than once in `licensePlate`, then it must appear in the word the same number of times or more.

For example, if `licensePlate` `= "aBc 12c"`, then it contains letters `'a'`, `'b'` (ignoring case), and `'c'` twice. Possible **completing** words are `"abccdef"`, `"caaacab"`, and `"cbca"`.

Return *the shortest **completing** word in* `words`*.* It is guaranteed an answer exists. If there are multiple shortest **completing** words, return the **first** one that occurs in `words`.

**Example 1:**

```
Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
"step" contains 't' and 'p', but only contains 1 's'.
"steps" contains 't', 'p', and both 's' characters.
"stripe" is missing an 's'.
"stepple" is missing an 's'.
Since "steps" is the only word containing all the letters, that is the answer.
```

**Example 2:**

```
Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
Output: "pest"
Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.
```

**Constraints:**

* `1 <= licensePlate.length <= 7`
* `licensePlate` contains digits, letters (uppercase or lowercase), or space `' '`.
* `1 <= words.length <= 1000`
* `1 <= words[i].length <= 15`
* `words[i]` consists of lower case English letters.

---

## Solution & Editorial
# Intuition
To find the shortest completing word, we first need to extract the required letter frequencies from the `licensePlate`, ignoring numbers, spaces, and case differences. Then, we evaluate each word in the dictionary to check if it satisfies all frequency requirements, keeping track of the shortest valid word encountered.

# Approach
1. Initialize a hash map `ls` to store the character counts of valid alphabetic characters in `licensePlate`, converted to lowercase using `tolower()`.
2. Maintain `mini` initialized to `INT_MAX` and `ans` as an empty string to track the length and value of the shortest completing word.
3. Iterate over each `word` in `words` and pass a copy of the license plate frequency map `ls` into the helper function `shortestWord`.
4. Inside the helper function, decrement counts in the copied map for each character present in the `word`. If a character count reaches zero, erase it from the map.
5. If the map becomes empty after processing a word (meaning all requirements are met) and the word's length is strictly smaller than `mini`, update `mini` and `ans`.

### Visual Trace Walkthrough (Example 1)
`licensePlate` = `"1s3 PSt"`, `words` = `["step","steps","stripe","stepple"]`
- `ls` frequency map: `{'s': 2, 'p': 1, 't': 1}`

| Word | Modified Map State | Map Empty? | Length | `mini` Update | `ans` Update |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `"step"` | `{'s': 1}` | No | 4 | No | `""` |
| `"steps"` | `{}` | Yes | 5 | Yes (`5 < INT_MAX`) | `"steps"` |
| `"stripe"` | `{'s': 1}` | No | 6 | No | `"steps"` |
| `"stepple"` | `{'s': 1}` | No | 7 | No | `"steps"` |

# Complexity
- Time complexity: $$O(N \cdot L)$$ — where $$N$$ is the number of words in `words` and $$L$$ is the maximum length of a word. For each word, we iterate through its characters at most $$L$$ times and perform hash map operations on at most 26 lowercase English letters ($$O(1)$$ average time per lookup/deletion).
- Space complexity: $$O(1)$$ — since the auxiliary space is bounded by the alphabet size (at most 26 lowercase characters) stored in the hash map and recursive/local function variables.

# Code
```cpp
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> ls;
        for(char c:licensePlate){
            if(isalpha(c)){
                ls[tolower(c)]++;
            } 
        }
        int mini = INT_MAX;
        string ans = "";
        for(auto& word : words){
            shortestWord(ls,word,ans,mini);
        }
        return ans;
    }

    void shortestWord(unordered_map<char,int> ls,string word,string& ans,int& mini){
        int length = word.size();
        for(char c:word){
            if(ls.count(c) && ls[c]>0){
                ls[c]--;
                if(ls[c] == 0) ls.erase(c);
            }
        }
        if(ls.empty() && length < mini){
            mini = length;
            ans = word;
        }
    }
};
```
