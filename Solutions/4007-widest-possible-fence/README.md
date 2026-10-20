# [4007. Widest Possible Fence](https://leetcode.com/problems/widest-possible-fence/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `counting`, `enumeration`

---

## Problem Description
You are given an integer array `planks`, where `planks[i]` represents the height of the `ith` wooden plank. Each plank has a width of 1 unit.

You want to build a fence consisting of planks that all have the **same** height.

You may either use a plank as is, or combine **exactly** two distinct original planks into a single plank whose height **equals** the sum of their heights. Each original plank can be used **at most** once, and not all original planks need to be used.

Return the **maximum possible width** of the fence that can be built.

**Example 1:**

**Input:** planks = [1,3,2,5,7,5,4,2,1]

**Output:** 4

**Explanation:**

We can have four planks of height 5.

* `planks[3] = 5`
* `planks[5] = 5`
* `planks[0] + planks[6] = 1 + 4 = 5`
* `planks[1] + planks[2] = 3 + 2 = 5`

Hence, the maximum width is 4.

**Example 2:**

**Input:** planks = [2,3,7]

**Output:** 1

**Explanation:**

* It is impossible to form two planks of the same height, even after combining two distinct original planks.
* Since not all original planks need to be used, we can choose any one plank as the fence.
* Therefore, the maximum possible width is 1.

**Constraints:**

* `1 <= planks.length <= 1000`
* `1 <= planks[i] <= 109`

---

## Solution & Editorial
# Intuition
To maximize the width of a fence with a uniform height $H$, we need to count how many planks of height $H$ we can form. A plank of height $H$ can be obtained either by using an existing plank of height $H$ or by summing two distinct planks $P_i$ and $P_j$ such that $P_i + P_j = H$. Since the number of planks is small ($N \le 1000$), we can iterate through all possible pairs of heights to calculate the potential frequency of every reachable sum.

# Approach
1. First, count the frequency of each plank height using a hash map `freq`.
2. Extract all unique heights into a vector `uniques` to avoid redundant processing.
3. Use a second hash map `mp` to store the total count of planks that can be formed for any target height $H$.
4. Iterate through all unique heights $h_1$ and $h_2$ (where $i \le j$):
   - If $i == j$, we can form $\lfloor freq[h_1] / 2 \rfloor$ planks of height $2 \times h_1$ by pairing identical planks, and we can also use the original $freq[h_1]$ planks of height $h_1$.
   - If $i < j$, we can form $\min(freq[h_1], freq[h_2])$ planks of height $h_1 + h_2$ by pairing one plank of height $h_1$ with one of height $h_2$.
5. The answer is the maximum value stored in `mp`.

### Visual Trace (Example 1: [1,3,2,5,7,5,4,2,1])
- `freq`: {1:2, 3:1, 2:2, 5:2, 7:1, 4:1}
- `uniques`: [1, 3, 2, 5, 7, 4]
- Processing $h_1=1, h_2=4$: $1+4=5$. `mp[5]` adds $\min(freq[1], freq[4]) = \min(2, 1) = 1$.
- Processing $h_1=3, h_2=2$: $3+2=5$. `mp[5]` adds $\min(freq[3], freq[2]) = \min(1, 2) = 1$.
- Original planks of height 5: `mp[5]` adds $freq[5] = 2$.
- Total `mp[5] = 1 + 1 + 2 = 4$.

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the number of unique plank heights. We iterate through all pairs of unique heights, which is at most $1000^2$ operations.
- Space complexity: $$O(N^2)$$ to store the counts of all possible sums in the hash map `mp`.

# Code
```cpp
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;
        for (int p : planks) {
            freq[p]++;
        }
        
        unordered_map<int, int> mp;
        vector<int> uniques;
        for (auto& pair : freq) {
            uniques.push_back(pair.first);
        }
        
        int n = uniques.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int h1 = uniques[i];
            mp[h1] += freq[h1];
            mp[h1 * 2] += freq[h1] / 2;
            for (int j = i + 1; j < n; j++) {
                int h2 = uniques[j];
                mp[h1 + h2] += min(freq[h1], freq[h2]);
            }
        }
        
        for (auto& pair : mp) {
            ans = max(ans, pair.second);
        }
        
        return ans;
    }
};
```
