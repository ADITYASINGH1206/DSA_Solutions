# [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `greedy`, `sorting`, `heap-priority-queue`

---

## Problem Description
You are given two positive **0-indexed** integer arrays `nums1` and `nums2`, both of length `n`.

The **sum of squared difference** of arrays `nums1` and `nums2` is defined as the **sum** of `(nums1[i] - nums2[i])2` for each `0 <= i < n`.

You are also given two positive integers `k1` and `k2`. You can modify any of the elements of `nums1` by `+1` or `-1` at most `k1` times. Similarly, you can modify any of the elements of `nums2` by `+1` or `-1` at most `k2` times.

Return *the minimum **sum of squared difference** after modifying array* `nums1` *at most* `k1` *times and modifying array* `nums2` *at most* `k2` *times*.

**Note**: You are allowed to modify the array elements to become **negative** integers.

**Example 1:**

```
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
```

**Example 2:**

```
Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.
```

**Constraints:**

* `n == nums1.length == nums2.length`
* `1 <= n <= 105`
* `0 <= nums1[i], nums2[i] <= 105`
* `0 <= k1, k2 <= 109`

---

## Solution & Editorial
# Intuition
To minimize the sum of squared differences $\sum (nums1[i] - nums2[i])^2$, we observe that the sum is dominated by the largest absolute differences. Reducing a larger difference by 1 provides a greater reduction in the total sum than reducing a smaller difference. Since we have a total budget of $K = k1 + k2$ operations, we should greedily reduce the largest absolute differences first.

# Approach
1. **Frequency Array**: Calculate the absolute difference for each pair $(nums1[i], nums2[i])$ and store the frequencies of these differences in a frequency array `difference` of size $10^5 + 1$. This allows us to process differences in $O(M)$ time where $M$ is the maximum possible difference.
2. **Greedy Reduction**: Iterate from the largest possible difference $i = 10^5$ down to $1$. For each difference $i$, if the total count of elements with this difference (`acc`) is less than or equal to our remaining budget `left`, we reduce all these elements to $i-1$ and update the budget. If `acc` exceeds `left`, we reduce only `left` elements from $i$ to $i-1$ and terminate.
3. **Final Calculation**: Once the budget is exhausted or all differences are reduced to 0, calculate the sum of squares using the updated frequencies.

### Visual Trace (Example 2: nums1=[1,4,10,12], nums2=[5,8,6,9], k1=1, k2=1)
- Initial diffs: $|1-5|=4, |4-8|=4, |10-6|=4, |12-9|=3$. Freqs: `diff[4]=3, diff[3]=1`.
- Budget `left = 2`.
- Iteration $i=4$: `acc = 3`. Since $3 > 2$, we reduce 2 elements from 4 to 3.
- `diff[4]` becomes $3-2=1$, `diff[3]` becomes $1+2=3$.
- Final state: `diff[4]=1, diff[3]=3`. Sum: $1(4^2) + 3(3^2) = 16 + 27 = 43$.

# Complexity
- Time complexity: $$O(N + M)$$ where $N$ is the number of elements and $M$ is the maximum possible difference ($10^5$). We iterate through the input once and then through the frequency array.
- Space complexity: $$O(M)$$ to store the frequency array of differences.

# Code
```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> difference( (int) 1e5+1);
        
        for(int i = 0; i<nums1.size();i++)
        {
            difference[abs(nums1[i] - nums2[i])]++;
        }
        
        int value = 0, left = k1+k2;
        int acc = 0;
        
        for(int i = (int) 1e5; i>=0; i--)
        {
            acc = difference[i];
            if(acc <= left)
            {
                if(i<=1)
                    return 0;
                
                difference[i-1] += difference[i];
                difference[i]=0;
                left -= acc;
            }
            else
            {
                if(i==0)
                    return 0;
                difference[i] -= left;
                difference[i-1] += left;
                break;
            }
        }
        long long answer = 0;
        
        for(int i = 1ll; i<=1e5; i++)
        {
            answer += (long long)difference[i] * ((long long)i*i);
        }
        
        return answer;
    }
};
```
