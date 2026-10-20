# [3684. Maximize Sum of At Most K Distinct Elements](https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `greedy`, `sorting`

---

## Problem Description
You are given a **positive** integer array `nums` and an integer `k`.

Choose at most `k` elements from `nums` so that their sum is maximized. However, the chosen numbers must be **distinct**.

Return an array containing the chosen numbers in **strictly descending** order.

**Example 1:**

**Input:** nums = [84,93,100,77,90], k = 3

**Output:** [100,93,90]

**Explanation:**

The maximum sum is 283, which is attained by choosing 93, 100 and 90. We rearrange them in strictly descending order as `[100, 93, 90]`.

**Example 2:**

**Input:** nums = [84,93,100,77,93], k = 3

**Output:** [100,93,84]

**Explanation:**

The maximum sum is 277, which is attained by choosing 84, 93 and 100. We rearrange them in strictly descending order as `[100, 93, 84]`. We cannot choose 93, 100 and 93 because the chosen numbers must be distinct.

**Example 3:**

**Input:** nums = [1,1,1,2,2,2], k = 6

**Output:** [2,1]

**Explanation:**

The maximum sum is 3, which is attained by choosing 1 and 2. We rearrange them in strictly descending order as `[2, 1]`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 109`
* `1 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
To maximize the sum of at most $k$ distinct elements, we must greedily select the largest available unique values from the input array. Since the problem requires the chosen elements to be distinct, the frequency of each number in the input is irrelevant; only their presence matters.

# Approach
1. Insert all elements from the input `nums` into a `std::set<int>`. This automatically handles two requirements: it removes all duplicates and keeps the elements in ascending order.
2. Initialize an empty vector `ans` to store the result.
3. Iterate through the set in reverse order (using `rbegin()` to `rend()`) to access the largest elements first.
4. Continue adding elements to `ans` until either the set is exhausted or we have collected exactly $k$ elements.
5. Return the `ans` vector, which will naturally be in strictly descending order due to the reverse iteration.

### Visual Trace (Example 1: nums = [84, 93, 100, 77, 90], k = 3)
| Step | Set (Sorted) | Iteration | Action | Result (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | {77, 84, 90, 93, 100} | 1st (100) | Add 100 | [100] |
| 2 | {77, 84, 90, 93, 100} | 2nd (93) | Add 93 | [100, 93] |
| 3 | {77, 84, 90, 93, 100} | 3rd (90) | Add 90 | [100, 93, 90] |

# Complexity
- Time complexity: $$O(N \log N)$$, where $N$ is the length of `nums`. Inserting $N$ elements into a `std::set` takes $O(N \log N)$, and the subsequent iteration takes $O(k)$, where $k \le N$.
- Space complexity: $$O(N)$$, as the `std::set` stores up to $N$ unique elements from the input array.

# Code
```cpp
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end()); 
        
        vector<int> ans;
        int count = 0;

        for(auto it = st.rbegin(); it != st.rend() && count < k; ++it){
            ans.push_back(*it);
            count++;
        }
        
        return ans;
    }
};
```
