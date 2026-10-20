# [1286. Iterator for Combination](https://leetcode.com/problems/iterator-for-combination/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `design`, `iterator`

---

## Problem Description
Design the `CombinationIterator` class:

* `CombinationIterator(string characters, int combinationLength)` Initializes the object with a string `characters` of **sorted distinct** lowercase English letters and a number `combinationLength` as arguments.
* `next()` Returns the next combination of length `combinationLength` in **lexicographical order**.
* `hasNext()` Returns `true` if and only if there exists a next combination.

**Example 1:**

```
Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
```

**Constraints:**

* `1 <= combinationLength <= characters.length <= 15`
* All the characters of `characters` are **unique**.
* At most `104` calls will be made to `next` and `hasNext`.
* It is guaranteed that all calls of the function `next` are valid.

---

## Solution & Editorial
# Intuition
The problem requires us to generate combinations of a given string in lexicographical order and serve them one by one through an iterator interface. Since the maximum length of characters is $15$, the total number of combinations is at most $\binom{15}{7} = 6435$, which easily fits in memory. We can pre-generate all valid combinations using backtracking during initialization and then simply serve them sequentially.

# Approach
1. **Initialization & Backtracking**: In the `CombinationIterator` constructor, invoke a recursive `backtrack` function that explores all subsets of the input string `characters` of length `combinationLength`.
2. **State Exploration**: At each index `i`, we branch into two choices: either include `characters[i]` in our current combination string `cur` or exclude it. Since we traverse indices from left to right, combinations are naturally generated in lexicographical order.
3. **Storage & Traversal**: Store all generated combinations in a `vector<string> arr`. Keep track of the current iteration index `i`. 
4. **Iterator Methods**: 
   - `next()` returns `arr[i]` and increments `i`.
   - `hasNext()` checks whether `i` is less than `arr.size()`.

### Visual Walkthrough (Example 1: `characters = "abc", combinationLength = 2`)
- `backtrack` explores subsets:
  - Include 'a', include 'b' $\rightarrow$ `cur = "ab"` (Valid, pushed to `arr`)
  - Include 'a', exclude 'b', include 'c' $\rightarrow$ `cur = "ac"` (Valid, pushed to `arr`)
  - Exclude 'a', include 'b', include 'c' $\rightarrow$ `cur = "bc"` (Valid, pushed to `arr`)
- `arr` becomes `["ab", "ac", "bc"]`.
- `next()` returns `"ab"`, `i` becomes `1`.
- `hasNext()` returns `true` ($1 < 3$).

# Complexity
- Time complexity: $$O(2^N \cdot L)$$ where $N$ is the length of `characters` and $L$ is `combinationLength`. Generating all subsets takes $O(2^N)$ operations, and copying strings of length up to $L$ takes $O(L)$ time per valid combination. Iterator calls `next()` and `hasNext()` take $$O(1)$$ time.
- Space complexity: $$O(2^N \cdot L)$$ to store all combinations in the vector `arr` and the recursion stack of depth up to $O(N)$.

# Code
```cpp
class CombinationIterator {
public:
    vector<string> arr;
    int i = 0;
    
    void backtrack(string &s, int len, int i, string &cur){
        if(i==s.size()){
            if(cur.size()==len) arr.push_back(cur);
            return;
        }
        cur.push_back(s[i]);
        backtrack(s,len,i+1,cur);
        cur.pop_back();
        backtrack(s,len,i+1,cur);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        backtrack(characters, combinationLength, 0, cur);
    }
    
    string next() {
        string ans = arr[i++];
        return ans;
    }
    
    bool hasNext() {
        return i<arr.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
