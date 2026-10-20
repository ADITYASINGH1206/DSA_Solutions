# [2391. Minimum Amount of Time to Collect Garbage](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** array of strings `garbage` where `garbage[i]` represents the assortment of garbage at the `ith` house. `garbage[i]` consists only of the characters `'M'`, `'P'` and `'G'` representing one unit of metal, paper and glass garbage respectively. Picking up **one** unit of any type of garbage takes `1` minute.

You are also given a **0-indexed** integer array `travel` where `travel[i]` is the number of minutes needed to go from house `i` to house `i + 1`.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house `0` and must visit each house **in order**; however, they do **not** need to visit every house.

Only **one** garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks **cannot** do anything.

Return *the **minimum** number of minutes needed to pick up all the garbage.*

**Example 1:**

```
Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
```

**Example 2:**

```
Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
```

**Constraints:**

* `2 <= garbage.length <= 105`
* `garbage[i]` consists of only the letters `'M'`, `'P'`, and `'G'`.
* `1 <= garbage[i].length <= 10`
* `travel.length == garbage.length - 1`
* `1 <= travel[i] <= 100`

---

## Solution & Editorial
# Intuition
The total time taken is the sum of the time spent picking up garbage and the time spent traveling. Since each truck only needs to travel as far as the last house containing its specific type of garbage, we can decouple the problem into three independent sub-problems (one for each truck) and sum their costs.

# Approach
1. **Identify Last Houses**: Iterate through the `garbage` array once to find the index of the last house containing 'G', 'P', and 'M'. Store these in `maxi_G`, `maxi_P`, and `maxi_M`.
2. **Calculate Costs**: For each truck type:
   - Iterate from house 0 up to the truck's respective last house index.
   - Add the travel time `travel[i-1]` for each step taken.
   - Count the occurrences of the specific garbage type at each house and add them to the total `ans`.

### Visual Trace (Example 1: garbage = ["G","P","GP","GG"], travel = [2,4,3])
| Truck | Last House Index | Travel Path | Garbage Count |
| :--- | :--- | :--- | :--- |
| Glass (G) | 3 | 0->1 (2), 1->2 (4), 2->3 (3) | 1+0+1+2 = 4 |
| Paper (P) | 2 | 0->1 (2), 1->2 (4) | 0+1+1+0 = 2 |
| Metal (M) | 0 | None | 0 |

*Total Time = (Travel_G + Count_G) + (Travel_P + Count_P) + (Travel_M + Count_M) = (9 + 4) + (6 + 2) + 0 = 21.*

# Complexity
- Time complexity: $$O(N + S)$$, where $$N$$ is the number of houses and $$S$$ is the total number of garbage units across all houses. We iterate through the houses to find the last indices and then iterate again to sum the travel and collection times.
- Space complexity: $$O(1)$$, as we only use a few integer variables to track indices and the running total, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int maxi_G = 0;
        int maxi_P = 0;
        int maxi_M = 0;
        int ans = 0;
        for(int i = 0 ;i < garbage.size();i++){
            for(char gar : garbage[i]){
                if(gar == 'G') maxi_G = max(maxi_G,i);
                else if(gar == 'M') maxi_M = max(maxi_M,i);
                else maxi_P = max(maxi_P,i);
            }
        }
        for(int i =0;i<=maxi_G;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'G') ans++;
            }
        }
        for(int i =0;i<=maxi_P;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'P') ans++;
            }
        }
        for(int i =0;i<=maxi_M;i++){
            if(i) ans += travel[i-1];
            for(char gar : garbage[i]){
                if(gar == 'M') ans++;
            }
        }
        return ans;
    }
};
```
