# [2605. Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `enumeration`

---

## Problem Description
Given two arrays of **unique** digits `nums1` and `nums2`, return *the **smallest** number that contains **at least** one digit from each array*.

**Example 1:**

```
Input: nums1 = [4,1,3], nums2 = [5,7]
Output: 15
Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
```

**Example 2:**

```
Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
Output: 3
Explanation: The number 3 contains the digit 3 which exists in both arrays.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 9`
* `1 <= nums1[i], nums2[i] <= 9`
* All digits in each array are **unique**.

---

## Solution & Editorial
# Intuition
To form the smallest number using at least one digit from each array, we have two scenarios:
1. **Intersection exists**: If there is a common digit, the smallest number is simply the smallest common digit.
2. **No intersection**: If there are no common digits, we must pick the smallest digit from `nums1` and the smallest from `nums2`. We then concatenate them to form the smallest possible two-digit number (e.g., if min1=1 and min2=5, we form 15).

# Approach
1. Use a boolean array `n` of size 10 to track the presence of digits in `nums1`.
2. Iterate through `nums1` to find the minimum digit `x` and mark its presence in `n`.
3. Iterate through `nums2` to find the minimum digit `y`. While doing so, check if the current digit exists in `n`. If it does, update `ans` with the minimum common digit found so far.
4. If a common digit was found (`valid` is true), return `ans`.
5. If no common digit exists, construct the smallest number by taking `min(x, y)` as the tens digit and `max(x, y)` as the units digit.

### Visual Trace (Example 1: nums1=[4,1,3], nums2=[5,7])
- `n` initialized to `[F, F, F, F, F, F, F, F, F, F]`
- After `nums1`: `x=1`, `n[4]=T, n[1]=T, n[3]=T`
- After `nums2`: `y=5`, `valid=false`
- Final: `ans = min(1, 5)*10 + max(1, 5) = 15`

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `nums1` and `nums2`. We iterate through each array exactly once.
- Space complexity: $$O(1)$$, as the boolean array `n` is of fixed size 10 regardless of input size.

# Code
```cpp
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool>n(10,false);
        int x = 10,y=10;
        int ans = 10;
        for(int num:nums1){
            x=min(x,num);
            n[num]=true;
        }
        bool valid =false;
        for(int num:nums2){
            if(n[num]){
                valid=true;
                ans=min(ans,num);
            }
            y=min(y,num);
        }
        if(valid){
            return ans;
        }
        ans = min(x,y)*10+max(x,y);
        return ans;
    }
};
```
