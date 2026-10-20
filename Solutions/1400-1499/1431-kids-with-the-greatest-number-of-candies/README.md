# [1431. Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
There are `n` kids with candies. You are given an integer array `candies`, where each `candies[i]` represents the number of candies the `ith` kid has, and an integer `extraCandies`, denoting the number of extra candies that you have.

Return *a boolean array* `result` *of length* `n`*, where* `result[i]` *is* `true` *if, after giving the* `ith` *kid all the* `extraCandies`*, they will have the **greatest** number of candies among all the kids**, or* `false` *otherwise*.

Note that **multiple** kids can have the **greatest** number of candies.

**Example 1:**

```
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
```

**Example 2:**

```
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
```

**Example 3:**

```
Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
```

**Constraints:**

* `n == candies.length`
* `2 <= n <= 100`
* `1 <= candies[i] <= 100`
* `1 <= extraCandies <= 50`

---

## Solution & Editorial
# Intuition
To determine if a kid can have the greatest number of candies, we only need to compare their total (current candies + extra) against the current maximum number of candies held by any kid in the group. If the sum is greater than or equal to the global maximum, that kid can potentially hold the greatest number of candies.

# Approach
1. First, perform a single pass over the `candies` array to identify the `maximum` value currently present.
2. Initialize a boolean vector `ans` to store the results.
3. Iterate through each kid's candy count `i` in the `candies` array. For each kid, check if `i + extraCandies >= maximum`.
4. Push `true` to `ans` if the condition holds, otherwise push `false`.

### Visual Trace (Example 1: candies = [2,3,5,1,3], extra = 3)
- **Step 1: Find Max**
  - `maximum` = max(2, 3, 5, 1, 3) = 5
- **Step 2: Compare**
  - Kid 1: 2 + 3 = 5 (5 >= 5) -> true
  - Kid 2: 3 + 3 = 6 (6 >= 5) -> true
  - Kid 3: 5 + 3 = 8 (8 >= 5) -> true
  - Kid 4: 1 + 3 = 4 (4 >= 5) -> false
  - Kid 5: 3 + 3 = 6 (6 >= 5) -> true

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of kids. We perform one pass to find the maximum and one pass to populate the result vector.
- Space complexity: $$O(N)$$ to store the boolean result vector of size $$N$$.

# Code
```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maximum = candies[0];
        for(int i=1; i<candies.size();i++){
            maximum=max(candies[i],maximum);
        }
        for(int i:candies){
            if((i+extraCandies)>=maximum){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
```
