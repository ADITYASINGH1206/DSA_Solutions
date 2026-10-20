# [2164. Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
You are given a **0-indexed** integer array `nums`. Rearrange the values of `nums` according to the following rules:

1. Sort the values at **odd indices** of `nums` in **non-increasing** order.
   * For example, if `nums = [4,1,2,3]` before this step, it becomes `[4,3,2,1]` after. The values at odd indices `1` and `3` are sorted in non-increasing order.
2. Sort the values at **even indices** of `nums` in **non-decreasing** order.
   * For example, if `nums = [4,1,2,3]` before this step, it becomes `[2,1,4,3]` after. The values at even indices `0` and `2` are sorted in non-decreasing order.

Return *the array formed after rearranging the values of* `nums`.

**Example 1:**

```
Input: nums = [4,1,2,3]
Output: [2,3,4,1]
Explanation: 
First, we sort the values present at odd indices (1 and 3) in non-increasing order.
So, nums changes from [4,1,2,3] to [4,3,2,1].
Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
So, nums changes from [4,1,2,3] to [2,3,4,1].
Thus, the array formed after rearranging the values is [2,3,4,1].
```

**Example 2:**

```
Input: nums = [2,1]
Output: [2,1]
Explanation: 
Since there is exactly one odd index and one even index, no rearrangement of values takes place.
The resultant array formed is [2,1], which is the same as the initial array.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires independent sorting of elements based on their index parity. Since the constraints are small (N <= 100), we can simply partition the elements into two separate containers based on whether their index is even or odd, sort them according to the specified criteria, and then merge them back into a result array.

# Approach
1. Initialize two vectors, `even` and `odd`, to store elements at even and odd indices respectively.
2. Iterate through the input `nums` once. If the index `i` is even, push `nums[i]` to `even`; otherwise, push it to `odd`.
3. Sort the `even` vector in non-decreasing order using `std::sort`.
4. Sort the `odd` vector in non-increasing order using `std::sort` with `rbegin()` and `rend()` iterators.
5. Create a result vector `ans` of size `n`. Iterate from `0` to `n-1`, placing elements from `even` and `odd` back into their respective parity positions.

### Visual Trace (Example 1: nums = [4, 1, 2, 3])
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Partition | even=[4, 2], odd=[1, 3] |
| 2 | Sort | even=[2, 4], odd=[3, 1] |
| 3 | Merge | ans[0]=2, ans[1]=3, ans[2]=4, ans[3]=1 |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of the array. This is dominated by the sorting of the two sub-vectors, which take $$O(N/2 \log N/2)$$ each.
- Space complexity: $$O(N)$$, as we use two auxiliary vectors to store the partitioned elements.

# Code
```cpp
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        int l = 0;
        int r = 0;
        for(int i = 0;i<n;i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            if(i%2==0) ans[i] = even[l++];
            else ans[i] = odd[r++];
        }
        return ans;
    }
};
```
