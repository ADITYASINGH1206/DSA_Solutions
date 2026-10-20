# [3909. Compare Sums of Bitonic Parts](https://leetcode.com/problems/compare-sums-of-bitonic-parts/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given a **bitonic** array `nums` of length `n`.

Split the array into **two** parts:

* **Ascending part**: from index 0 to the peak element (inclusive).
* **Descending part**: from the peak element to index `n - 1` (inclusive).

The peak element belongs to both parts.

Return:

* 0 if the sum of the **ascending** part is greater.
* 1 if the sum of the **descending** part is greater.
* -1 if both sums are **equal**.

**Notes**:

* A **bitonic** array is an array that is **strictly increasing** up to a **single peak** element and then **strictly decreasing**.
* An array is said to be **strictly increasing** if each element is **strictly greater** than its **previous** one (if exists).
* An array is said to be **strictly decreasing** if each element is **strictly smaller** than its **previous** one (if exists).

**Example 1:**

**Input:** nums = [1,3,2,1]

**Output:** 1

**Explanation:**

* Peak element is `nums[1] = 3`
* Ascending part = `[1, 3]`, sum is `1 + 3 = 4`
* Descending part = `[3, 2, 1]`, sum is `3 + 2 + 1 = 6`
* Since the descending part has a larger sum, return 1.

**Example 2:**

**Input:** nums = [2,4,5,2]

**Output:** 0

**Explanation:**

* Peak element is `nums[2] = 5`
* Ascending part = `[2, 4, 5]`, sum is `2 + 4 + 5 = 11`
* Descending part = `[5, 2]`, sum is `5 + 2 = 7`
* Since the ascending part has a larger sum, return 0.

**Example 3:**

**Input:** nums = [1,2,4,3]

**Output:** -1

**Explanation:**

* Peak element is `nums[2] = 4`
* Ascending part = `[1, 2, 4]`, sum is `1 + 2 + 4 = 7`
* Descending part = `[4, 3]`, sum is `4 + 3 = 7`
* Since both parts have equal sums, return -1.

**Constraints:**

* `3 <= n == nums.length <= 105`
* `1 <= nums[i] <= 109`
* `nums` is a bitonic array.

---

## Solution & Editorial
# Intuition
Since the array is bitonic, it contains exactly one peak element. The problem requires splitting the array at this peak and comparing the sums of the two resulting segments. Because the peak is included in both segments, we can identify its index and calculate the prefix sum up to the peak and the suffix sum starting from the peak.

# Approach
1. Find the peak element using `std::max_element` and locate its index `idx` by iterating through the array.
2. Calculate `leftsum` by iterating from index `0` to `idx`.
3. Calculate `rightsum` by iterating from index `idx` to `n - 1`.
4. Compare `leftsum` and `rightsum` to return the appropriate result (0, 1, or -1).

### Visual Trace (Example 1: nums = [1, 3, 2, 1])
| Step | Variable | Value |
| :--- | :--- | :--- |
| Find Peak | `maxi` | 3 |
| Find Index | `idx` | 1 |
| Sum Left | `leftsum` | 1 + 3 = 4 |
| Sum Right | `rightsum` | 3 + 2 + 1 = 6 |
| Compare | `4 < 6` | Result: 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass to find the peak index and two partial passes to compute the sums.
- Space complexity: $$O(1)$$, as we only use a few integer variables to store the sums and indices, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int idx = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] == maxi){
                idx = i;
                break;
            }
        }

        long long leftsum = 0;
        long long rightsum = 0;
        
        for(int i = 0;i<=idx;i++){
            leftsum += nums[i];
        }
        for(int i = idx;i<n;i++){
            rightsum += nums[i];
        }
        if(leftsum > rightsum) return 0;
        else if(rightsum > leftsum) return 1;
        else return -1;
    }
};
```
