# [2091. Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given a **0-indexed** array of **distinct** integers `nums`.

There is an element in `nums` that has the **lowest** value and an element that has the **highest** value. We call them the **minimum** and **maximum** respectively. Your goal is to remove **both** these elements from the array.

A **deletion** is defined as either removing an element from the **front** of the array or removing an element from the **back** of the array.

Return the **minimum** number of deletions it would take to remove **both** the **minimum** and **maximum** element from the array.

**Example 1:**

```
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
```

**Example 2:**

```
Input: nums = [0,-4,19,1,8,-2,-3,5]
Output: 3
Explanation: 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
```

**Example 3:**

```
Input: nums = [101]
Output: 1
Explanation:  
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-105 <= nums[i] <= 105`
* The integers in `nums` are **distinct**.

---

## Solution & Editorial
# Intuition
To remove both the minimum and maximum elements, we have three distinct strategies based on their positions relative to the array boundaries (front and back). Since we can only remove from the ends, we calculate the cost for each strategy and select the minimum.

# Approach
1. Identify the indices of the minimum (`minIndex`) and maximum (`maxIndex`) elements using `std::min_element` and `std::max_element`.
2. Define `left` as the smaller index and `right` as the larger index to simplify boundary calculations.
3. Evaluate the three possible strategies:
   - **Both from front:** Remove all elements up to `right`. Cost: `right + 1`.
   - **Both from back:** Remove all elements from `left` to the end. Cost: `n - left`.
   - **One from front, one from back:** Remove elements up to `left` from the front and elements from `right` to the end from the back. Cost: `(left + 1) + (n - right)`.
4. Return the minimum of these three values.

### Visual Trace (Example 1: nums = [2, 10, 7, 5, 4, 1, 8, 6])
- `minIndex` = 5 (value 1), `maxIndex` = 1 (value 10)
- `left` = 1, `right` = 5, `n` = 8
- Strategy 1 (Front): `right + 1` = 6
- Strategy 2 (Back): `n - left` = 8 - 1 = 7
- Strategy 3 (Split): `(left + 1) + (n - right)` = (1 + 1) + (8 - 5) = 2 + 3 = 5
- Result: `min(6, 7, 5)` = 5

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform two linear scans to find the min and max indices.
- Space complexity: $$O(1)$$, as we only store a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int front = right + 1;
        int back = n - left;

        int frontBack = (left + 1) + (n - right);

        return min({front, back, frontBack});
    }
};
```
