# [2559. Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** array of strings `words` and a 2D array of integers `queries`.

Each query `queries[i] = [li, ri]` asks us to find the number of strings present at the indices ranging from `li` to `ri` (both **inclusive**) of `words` that start and end with a vowel.

Return *an array* `ans` *of size* `queries.length`*, where* `ans[i]` *is the answer to the* `i`th *query*.

**Note** that the vowel letters are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

```
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
```

**Example 2:**

```
Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
```

**Constraints:**

* `1 <= words.length <= 105`
* `1 <= words[i].length <= 40`
* `words[i]` consists only of lowercase English letters.
* `sum(words[i].length) <= 3 * 105`
* `1 <= queries.length <= 105`
* `0 <= li <= ri < words.length`

---

## Solution & Editorial
# Intuition
To efficiently answer range queries about strings starting and ending with vowels, we must avoid re-scanning the strings for every query. By pre-calculating the cumulative count of such strings, we can transform any range query into a constant-time subtraction operation.

# Approach
1. **Vowel Identification**: Define a helper function `isVowel` to check if a character is one of 'a', 'e', 'i', 'o', or 'u'.
2. **Prefix Sum Array**: Create a `prefix` array of size `n` (where `n` is the number of words). Iterate through `words`, maintaining a running `count` of strings that satisfy the vowel condition. Store the current `count` at each index `i` in `prefix[i]`.
3. **Query Processing**: For each query `[l, r]`, the number of valid strings is `prefix[r] - prefix[l-1]`. If `l == 0`, the answer is simply `prefix[r]`.

### Visual Trace (Example 1)
`words = ["aba", "bcb", "ece", "aa", "e"]`

| Index | Word | Vowel Start/End? | Running Count | Prefix[i] |
| :--- | :--- | :--- | :--- | :--- |
| 0 | "aba" | Yes | 1 | 1 |
| 1 | "bcb" | No | 1 | 1 |
| 2 | "ece" | Yes | 2 | 2 |
| 3 | "aa" | Yes | 3 | 3 |
| 4 | "e" | Yes | 4 | 4 |

Query `[1, 2]` would be `prefix[2] - prefix[0] = 2 - 1 = 1`.

# Complexity
- Time complexity: $$O(N + Q)$$, where $$N$$ is the number of words and $$Q$$ is the number of queries. We perform a single pass over the words to build the prefix array and a single pass over the queries to compute the results.
- Space complexity: $$O(N)$$ to store the prefix sum array.

# Code
```cpp
class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n,0);
        vector<int>ans;
        int count=0;
        for(int i =0;i<n;i++){
            string&s = words[i];
            if(isVowel(s.front())&&isVowel(s.back())){
                count++;
            }
            prefix[i]=count;
        }
        for(auto&query:queries){
            int l = query[0];
            int r = query[1];
            if(l>0){
                ans.push_back(prefix[r]-prefix[l-1]);
            }else{
                ans.push_back(prefix[r]);
            }
        }
        return ans;
    }
};
```
