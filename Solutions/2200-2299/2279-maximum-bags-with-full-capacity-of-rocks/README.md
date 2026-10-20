# [2279. Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You have `n` bags numbered from `0` to `n - 1`. You are given two **0-indexed** integer arrays `capacity` and `rocks`. The `ith` bag can hold a maximum of `capacity[i]` rocks and currently contains `rocks[i]` rocks. You are also given an integer `additionalRocks`, the number of additional rocks you can place in **any** of the bags.

Return *the **maximum** number of bags that could have full capacity after placing the additional rocks in some bags.*

**Example 1:**

```
Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
Output: 3
Explanation:
Place 1 rock in bag 0 and 1 rock in bag 1.
The number of rocks in each bag are now [2,3,4,4].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that there may be other ways of placing the rocks that result in an answer of 3.
```

**Example 2:**

```
Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
Output: 3
Explanation:
Place 8 rocks in bag 0 and 2 rocks in bag 2.
The number of rocks in each bag are now [10,2,2].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that we did not use all of the additional rocks.
```

**Constraints:**

* `n == capacity.length == rocks.length`
* `1 <= n <= 5 * 104`
* `1 <= capacity[i] <= 109`
* `0 <= rocks[i] <= capacity[i]`
* `1 <= additionalRocks <= 109`

---

## Solution & Editorial
# Intuition
To maximize the number of full bags, we should prioritize filling bags that require the fewest additional rocks. This is a classic greedy problem: by sorting the remaining capacity needed for each bag in ascending order, we ensure that each unit of `additionalRocks` contributes to filling as many bags as possible.

# Approach
1. Calculate the deficit for each bag: `diff[i] = capacity[i] - rocks[i]`. This represents the number of rocks needed to make bag `i` full.
2. Sort the `diff` array in non-decreasing order. This allows us to greedily fill the bags that are "closest" to being full first.
3. Iterate through the sorted `diff` array. For each bag, if `additionalRocks` is greater than or equal to the required `diff[i]`, subtract the cost from `additionalRocks` and mark the bag as full (setting `diff[i] = 0`).
4. Count the number of bags where `diff[i] == 0`.

### Visual Trace (Example 1)
`capacity = [2,3,4,5]`, `rocks = [1,2,4,4]`, `additionalRocks = 2`
- Initial `diff`: `[1, 1, 0, 1]`
- Sorted `diff`: `[0, 1, 1, 1]`
- Iteration 1: `diff[0]=0`, `additionalRocks=2`, count=1
- Iteration 2: `diff[1]=1`, `additionalRocks=2 >= 1`, `additionalRocks` becomes 1, `diff[1]=0`, count=2
- Iteration 3: `diff[2]=1`, `additionalRocks=1 >= 1`, `additionalRocks` becomes 0, `diff[2]=0`, count=3
- Iteration 4: `diff[3]=1`, `additionalRocks=0 < 1`, loop ends.
- Result: 3

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting of the `diff` array, where $$N$$ is the number of bags. The subsequent linear scans are $$O(N)$$.
- Space complexity: $$O(N)$$ to store the `diff` array.

# Code
```cpp
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff(n);

        long long totaldiff=0;
        for(int i=0; i<n; i++){
            totaldiff+=(capacity[i]-rocks[i]);
        }

        if(totaldiff<=additionalRocks)
            return n;

        for(int i=0; i<n; i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(), diff.end());

        for(int i=0; i<n; i++){
            if(additionalRocks>=diff[i]){
                additionalRocks-=diff[i];
                diff[i]=0;
            }
        }

        int cnt=0;

        for(int i=0; i<n; i++){
            if(diff[i]==0)
                cnt++;
        }

        return cnt;
    }
};
```
