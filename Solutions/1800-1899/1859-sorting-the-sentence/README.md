# [1859. Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence/)
**Difficulty:** `Easy` | **Tags:** `string`, `sorting`, `bubble-sort`

---

## Problem Description
A **sentence** is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be **shuffled** by appending the **1-indexed word position** to each word then rearranging the words in the sentence.

* For example, the sentence `"This is a sentence"` can be shuffled as `"sentence4 a3 is2 This1"` or `"is2 sentence4 This1 a3"`.

Given a **shuffled sentence** `s` containing no more than `9` words, reconstruct and return *the original sentence*.

**Example 1:**

```
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
```

**Example 2:**

```
Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
```

**Constraints:**

* `2 <= s.length <= 200`
* `s` consists of lowercase and uppercase English letters, spaces, and digits from `1` to `9`.
* The number of words in `s` is between `1` and `9`.
* The words in `s` are separated by a single space.
* `s` contains no leading or trailing spaces.

---

## Solution & Editorial
# Intuition
Since the number of words in the sentence is small (at most 9) and each word contains a 1-indexed position digit, we can treat these digits as bucket indices. By iterating through the string once, we can place each word directly into its correct position in a pre-allocated array.

# Approach
1. Initialize a vector of strings `order` of size 10 to store words at their respective 1-indexed positions.
2. Iterate through each character `ch` in the input string `s`:
   - If `ch` is a digit ('1'-'9'), it marks the end of a word. Store the accumulated `temp` string into `order[ch - '0']` and clear `temp`.
   - If `ch` is an alphabetic character, append it to `temp`.
3. Construct the final result by iterating through `order` from index 1 to 9, appending each non-empty word followed by a space.
4. Remove the trailing space from the final string before returning.

### Visual Trace (Example 1: "is2 sentence4 This1 a3")
| Iteration | Char | Action | `temp` | `order` State |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 'i' | Append | "i" | - |
| 2 | 's' | Append | "is" | - |
| 3 | '2' | Store | "" | `order[2] = "is"` |
| 4 | 's' | Append | "s" | - |
| ... | ... | ... | ... | ... |
| Final | - | Join | - | `order[1]="This", order[2]="is", order[3]="a", order[4]="sentence"` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once, and the subsequent construction of the result string also takes linear time relative to the total number of characters.
- Space complexity: $$O(N)$$, as we store the words in an auxiliary vector of strings which, in total, holds all characters of the input string.

# Code
```cpp
class Solution {
public:
    string sortSentence(string s) {
        vector<string>order(10,"");
        string temp;
        for(char ch :s){
            if(ch>='1' && ch<='9'){
                order[ch-'0']=temp;
                temp.clear();
            }
            if(isalpha(ch)){
                temp+=ch;
            }
        }
        string ans ;
        for(int i = 0;i<10;i++){
            if(order[i]!=""){
                ans+=order[i];
                ans+=" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};
```
