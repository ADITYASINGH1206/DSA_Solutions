# [1122. Relative Sort Array](https://leetcode.com/problems/relative-sort-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `counting-sort`, `quicksort`, `bubble-sort`

---

## Problem Description
Given two arrays `arr1` and `arr2`, the elements of `arr2` are distinct, and all elements in `arr2` are also in `arr1`.

Sort the elements of `arr1` such that the relative ordering of items in `arr1` are the same as in `arr2`. Elements that do not appear in `arr2` should be placed at the end of `arr1` in **ascending** order.

**Example 1:**

```
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

**Example 2:**

```
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
```

**Constraints:**

* `1 <= arr1.length, arr2.length <= 1000`
* `0 <= arr1[i], arr2[i] <= 1000`
* All the elements of `arr2` are **distinct**.
* Each `arr2[i]` is in `arr1`.

---

## Solution & Editorial
# Intuition
The problem requires sorting elements of `arr1` according to a custom relative order specified by `arr2`, with any remaining elements placed at the end in ascending order. Given that the element values are bounded up to 1000, we can use a frequency array (Counting Sort) to record the occurrences of each element in `arr1` and then reconstruct the result vector in the exact required order.

# Approach
1. Find the maximum element `maxi` in `arr1` to determine the size of our frequency array `count` of size `maxi + 1` initialized to zero.
2. Iterate through `arr1` and populate the frequency of each element in `count`.
3. Iterate through `arr2`, and for each element, append it to the answer vector `ans` as many times as its frequency in `count`, decrementing the frequency until it reaches zero.
4. Iterate through all possible values from `0` to `maxi`. For any element that still has a non-zero frequency (meaning it was not present in `arr2`), append it to `ans` in ascending order.
5. Return the resulting vector `ans`.

### Visual Walkthrough (Example 1)
`arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19]`, `arr2 = [2, 1, 4, 3, 9, 6]`
- `maxi = 19`
- `count` frequencies populated: `count[1]=2, count[2]=3, count[3]=2, count[4]=1, count[6]=1, count[7]=1, count[9]=1, count[19]=1`
- Processing `arr2`: 
  - `num = 2`: appends `2, 2, 2`
  - `num = 1`: appends `1`
  - `num = 4`: appends `4`
  - `num = 3`: appends `3, 3`
  - `num = 9`: appends `9`
  - `num = 6`: appends `6`
- Processing remaining from `0` to `19`:
  - `num = 7`: appends `7`
  - `num = 19`: appends `19`
- Final `ans`: `[2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19]`

# Complexity
- Time complexity: $$O(N + M + K)$$ where $$N$$ is the size of `arr1`, $$M$$ is the size of `arr2`, and $$K$$ is the maximum value in `arr1`. Finding the maximum takes $$O(N)$$, populating counts takes $$O(N)$$, processing `arr2` takes $$O(N)$$ total across all inner loop pops, and final traversal takes $$O(K)$$.
- Space complexity: $$O(K)$$ for the frequency vector `count` of size `maxi + 1`, and $$O(N)$$ for the output vector `ans`.

# Code
```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxi + 1);

        for (int num : arr1) {
            count[num]++;
        }

        vector<int> ans;
        for (int num : arr2) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        for (int num = 0; num <= maxi; num++) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        return ans;
    }
};
```
