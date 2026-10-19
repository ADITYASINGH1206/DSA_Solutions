# [769. Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `greedy`, `sorting`, `monotonic-stack`

---

## Problem Description
You are given an integer array `arr` of length `n` that represents a permutation of the integers in the range `[0, n - 1]`.

We split `arr` into some number of **chunks** (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return *the largest number of chunks we can make to sort the array*.

**Example 1:**

```
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
```

**Example 2:**

```
Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
```

**Constraints:**

* `n == arr.length`
* `1 <= n <= 10`
* `0 <= arr[i] < n`
* All the elements of `arr` are **unique**.

---

## Solution & Editorial
# Intuition
Since the array is a permutation of integers from $0$ to $n - 1$, a valid chunk ending at index $i$ must contain all numbers from the range of its indices. This means that the cumulative sum of elements up to index $i$ must equal the cumulative sum of indices from $0$ to $i$. By tracking the running difference between the array elements and their respective indices, whenever this difference hits zero, all elements seen so far belong strictly to the current prefix and can be formed into a valid independent chunk.

# Approach
1. Initialize `n` as the size of the array `arr`, `ans` to store the maximum number of chunks, and `diff` to maintain the running sum of `arr[i] - i`.
2. Iterate through the array from `i = 0` to `n - 1` using a standard `for` loop.
3. At each index `i`, update `diff` by adding `arr[i] - i`.
4. If `diff == 0`, it signifies that the set of elements encountered so far matches the set of expected indices `[0, i]`, allowing us to increment `ans` by 1.
5. Return `ans` after completing the traversal.

### Visual Trace Walkthrough
Example: `arr = [1, 0, 2, 3, 4]`

| Index `i` | `arr[i]` | `arr[i] - i` | Cumulative `diff` | `diff == 0?` | `ans` | Explanation |
| :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| 0 | 1 | 1 - 0 = 1 | 1 | No | 0 | Prefix sum mismatch |
| 1 | 0 | 0 - 1 = -1 | 0 | Yes | 1 | Chunk `[1, 0]` finalized |
| 2 | 2 | 2 - 2 = 0 | 0 | Yes | 2 | Chunk `[2]` finalized |
| 3 | 3 | 3 - 3 = 0 | 0 | Yes | 3 | Chunk `[3]` finalized |
| 4 | 4 | 4 - 4 = 0 | 0 | Yes | 4 | Chunk `[4]` finalized |

# Complexity
- Time complexity: $$O(n)$$ — We perform a single linear scan of the array of size $n$, doing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables are used for tracking, requiring no auxiliary memory.

# Code
```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            if(diff==0) ans++;
        }
        return ans;
    }
};
```
