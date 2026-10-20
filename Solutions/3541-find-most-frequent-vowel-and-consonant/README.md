# [3541. Find Most Frequent Vowel and Consonant](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters (`'a'` to `'z'`).

Your task is to:

* Find the vowel (one of `'a'`, `'e'`, `'i'`, `'o'`, or `'u'`) with the **maximum** frequency.
* Find the consonant (all other letters excluding vowels) with the **maximum** frequency.

Return the sum of the two frequencies.

**Note**: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.

The **frequency** of a letter `x` is the number of times it occurs in the string.

**Example 1:**

**Input:** s = "successes"

**Output:** 6

**Explanation:**

* The vowels are: `'u'` (frequency 1), `'e'` (frequency 2). The maximum frequency is 2.
* The consonants are: `'s'` (frequency 4), `'c'` (frequency 2). The maximum frequency is 4.
* The output is `2 + 4 = 6`.

**Example 2:**

**Input:** s = "aeiaeia"

**Output:** 3

**Explanation:**

* The vowels are: `'a'` (frequency 3), `'e'` ( frequency 2), `'i'` (frequency 2). The maximum frequency is 3.
* There are no consonants in `s`. Hence, maximum consonant frequency = 0.
* The output is `3 + 0 = 3`.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of lowercase English letters only.

---

## Solution & Editorial
# Intuition
To solve this problem, we need to categorize characters into two groups: vowels and consonants. By counting the occurrences of each character using a hash map, we can efficiently determine the maximum frequency within each group independently and sum them up.

# Approach
1. Initialize an `unordered_map<char, int>` to store the frequency of every character present in the string `s`.
2. Iterate through the string `s` once to populate the map.
3. Initialize two integer variables, `max_vowels` and `max_conso`, to 0.
4. Iterate through the map. For each key-value pair:
   - Check if the character is a vowel ('a', 'e', 'i', 'o', 'u').
   - If it is a vowel, update `max_vowels = max(max_vowels, frequency)`.
   - Otherwise, update `max_conso = max(max_conso, frequency)`.
5. Return the sum `max_vowels + max_conso`.

### Visual Trace (Example 1: "successes")
| Step | Char | Map State | max_vowels | max_conso |
| :--- | :--- | :--- | :--- | :--- |
| Init | - | {} | 0 | 0 |
| Process 's' | s | {s:1} | 0 | 1 |
| Process 'u' | u | {s:1, u:1} | 1 | 1 |
| Process 'c' | c | {s:1, u:1, c:1} | 1 | 1 |
| ... | ... | {s:4, u:1, c:2, e:2} | 2 | 4 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform one pass to count frequencies and one pass over the unique characters (at most 26) in the map.
- Space complexity: $$O(1)$$, as the map stores at most 26 lowercase English letters, which is constant space.

# Code
```cpp
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }

        int max_vowels=0;
        int max_conso=0;

        for(auto p:mp){
           char c = p.first;
           int frequency = p.second;

           if(c =='a' || c =='e' || c =='i' || c=='o' || c=='u'){
            max_vowels=max(max_vowels , frequency);
           }
           else{
            max_conso=max(max_conso , frequency);
           }
        }
        return max_vowels + max_conso;
        
    }
};
```
