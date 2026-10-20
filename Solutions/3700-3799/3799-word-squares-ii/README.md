# [3799. Word Squares II](https://leetcode.com/problems/word-squares-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `backtracking`, `sorting`, `enumeration`

---

## Problem Description
You are given a string array `words`, consisting of **distinct** 4-letter strings, each containing lowercase English letters.

A **word square** consists of 4 **distinct** words: `top`, `left`, `right` and `bottom`, arranged as follows:

* `top` forms the **top row**.
* `bottom` forms the **bottom row**.
* `left` forms the **left column** (top to bottom).
* `right` forms the **right column** (top to bottom).

It must satisfy:

* `top[0] == left[0]`, `top[3] == right[0]`
* `bottom[0] == left[3]`, `bottom[3] == right[3]`

Return all valid **distinct** word squares, sorted in **ascending lexicographic** order by the 4-tuple `(top, left, right, bottom)​​​​​​​`.

**Example 1:**

**Input:** words = ["able","area","echo","also"]

**Output:** [["able","area","echo","also"],["area","able","also","echo"]]

**Explanation:**

There are exactly two valid 4-word squares that satisfy all corner constraints:

* `"able"` (top), `"area"` (left), `"echo"` (right), `"also"` (bottom)
  + `top[0] == left[0] == 'a'`
  + `top[3] == right[0] == 'e'`
  + `bottom[0] == left[3] == 'a'`
  + `bottom[3] == right[3] == 'o'`
* `"area"` (top), `"able"` (left), `"also"` (right), `"echo"` (bottom)
  + All corner constraints are satisfied.

Thus, the answer is `[["able","area","echo","also"],["area","able","also","echo"]]`.

**Example 2:**

**Input:** words = ["code","cafe","eden","edge"]

**Output:** []

**Explanation:**

No combination of four words satisfies all four corner constraints. Thus, the answer is empty array `[]`.

**Constraints:**

* `4 <= words.length <= 15`
* `words[i].length == 4`
* `words[i]` consists of only lowercase English letters.
* All `words[i]` are **distinct**.

---

## Solution & Editorial
# Intuition
The problem asks us to select 4 distinct words from a given list to form a specific geometric configuration (a word square). Since the number of words is small ($N \le 15$), we can explore all possible permutations of 4-word combinations using backtracking and verify the corner constraints for each valid permutation.

# Approach
1. **Sorting**: First, sort the input `words` array lexicographically. This ensures that when we generate permutations, the resulting valid squares are naturally discovered in lexicographical order.
2. **Backtracking**: Use a recursive function `backtrack` to pick 4 distinct words from the input. We maintain a `visited` boolean array to ensure each word is used only once per square.
3. **Validation**: Once the `current` vector contains 4 words (representing `top`, `left`, `right`, and `bottom` in order), check the constraints:
   - `top[0] == left[0]`
   - `top[3] == right[0]`
   - `bottom[0] == left[3]`
   - `bottom[3] == right[3]`
4. **State Trace (Example 1: words = ["able", "also", "area", "echo"])**:
   - `depth 0`: Pick "able" (top)
   - `depth 1`: Pick "area" (left)
   - `depth 2`: Pick "echo" (right)
   - `depth 3`: Pick "also" (bottom)
   - `Check`: `able[0]==area[0]` ('a'=='a'), `able[3]==echo[0]` ('e'=='e'), `also[0]==area[3]` ('a'=='a'), `also[3]==echo[3]` ('o'=='o'). Valid!

# Complexity
- Time complexity: $$O(P(N, 4)) = O(N \cdot (N-1) \cdot (N-2) \cdot (N-3))$$, which simplifies to $$O(N^4)$$. Given $N \le 15$, $15 \times 14 \times 13 \times 12 = 32,760$ operations, well within the time limit.
- Space complexity: $$O(N)$$ for the recursion stack and the `visited` array.

# Code
```cpp
class Solution {
public:
    void backtrack(vector<string>& words, vector<bool>& visited, vector<string>& current, vector<vector<string>>& ans) {
        if (current.size() == 4) {
            if (current[0][0] == current[1][0] && 
                current[0][3] == current[2][0] &&
                current[3][0] == current[1][3] &&
                current[3][3] == current[2][3]) {
                
                ans.push_back(current);
            }
            return;
        }

        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;          
                current.push_back(words[i]); 
                
                backtrack(words, visited, current, ans); 
                
                current.pop_back();         
                visited[i] = false;         
            }
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        vector<string> current;
        vector<bool> visited(words.size(), false);
        sort(words.begin(), words.end());
        backtrack(words, visited, current, ans);
        
        return ans;
    }
};
```
