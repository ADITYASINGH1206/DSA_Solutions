# [3984. Divisible Game](https://leetcode.com/problems/divisible-game/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`, `enumeration`, `number-theory`

---

## Problem Description
You are given an integer array `nums` of length `n`.

Alice and Bob are playing a game. Alice chooses:

* An integer `k` such that `k > 1`.
* Two integers `l` and `r` such that `0 <= l <= r < n`.

Initially, both Alice's and Bob's scores are 0.

For each index `i` in the range `[l, r]` (inclusive):

* If `nums[i]` is divisible by `k`, Alice's score **increases** by `nums[i]`.
* Otherwise, Bob's score **increases** by `nums[i]`.

The **score difference** is Alice's score **minus** Bob's score.

Alice wants to **maximize** the score difference. If there are multiple values of `k` that achieve the **maximum** score difference, she chooses the **smallest** such `k`.

Return the **product** of the **maximum** score difference and the chosen value of `k`. Since the result can be large, return it **modulo** `109 + 7`.

**Example 1:**

**Input:** nums = [1,4,6,8]

**Output:** 36

**Explanation:**

* Alice can choose `k = 2`, `l = 1`, and `r = 3`.
* All values in `nums[1..3]` are divisible by 2, so Alice's score is `4 + 6 + 8 = 18`, while Bob's score is 0.
* The score difference is 18, which is the maximum possible. Among all values of `k` that achieve this score difference, the smallest is 2.
* Therefore, the answer is `18 * 2 = 36`.

**Example 2:**

**Input:** nums = [2,1,2]

**Output:** 6

**Explanation:**

* Alice can choose `k = 2`, `l = 0`, and `r = 2`.
* The values `nums[0]` and `nums[2]` are divisible by 2, so Alice's score is `2 + 2 = 4`. The value `nums[1]` is not divisible by 2, so Bob's score is 1.
* The score difference is `4 - 1 = 3`, which is the maximum possible. Among all values of `k` that achieve this score difference, the smallest is 2.
* Therefore, the answer is `3 * 2 = 6`.

**Example 3:**

**Input:** nums = [1]

**Output:** 1000000005

**Explanation:**

* Alice must choose some `k > 1`. The smallest possible choice is `k = 2`.
* Since `nums[0]` is not divisible by 2, Alice's score is 0, while Bob's score is 1.
* The score difference is -1, which is the maximum possible.
* Therefore, the answer is `-1 * 2 = -2`. Modulo `109 + 7`, this equals 1000000005.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To maximize the score difference for a fixed $k$, we observe that for any subarray $[l, r]$, the score difference is $\sum_{i=l}^r f(nums[i], k)$, where $f(x, k) = x$ if $x \equiv 0 \pmod k$ and $f(x, k) = -x$ otherwise. This is equivalent to finding the Maximum Subarray Sum where elements divisible by $k$ are positive and others are negative. Since we need to iterate over possible $k$ values up to the maximum element in `nums`, we optimize the subarray search using a Kadane-like approach.

# Approach
1. Precompute a prefix sum array `pref` to calculate the sum of non-divisible elements in $O(1)$ time.
2. Map each value in `nums` to its indices using `val_to_indices` to quickly identify which elements are divisible by $k$.
3. For each $k \in [2, \max(nums)]$, identify indices where $nums[i] \equiv 0 \pmod k$. Let these indices be $idx_1, idx_2, \dots, idx_m$.
4. The score difference for a range $[l, r]$ is: (Sum of multiples of $k$ in range) - (Sum of non-multiples of $k$ in range).
5. Use a Kadane-like logic: iterate through the sorted indices of multiples. Between two consecutive multiples $idx_j$ and $idx_{j+1}$, the non-multiples contribute a negative sum equal to $-(pref[idx_{j+1}] - pref[idx_j + 1])$.
6. Track the global maximum score difference and the smallest $k$ that achieves it.

### Visual Trace (Example 1: [1, 4, 6, 8], k=2)
- Multiples of 2: indices {1, 2, 3} (values 4, 6, 8).
- Non-multiples: index {0} (value 1).
- Kadane logic: 
  - Start at index 1: `current_sum` = 4.
  - Move to index 2: `gap` = -(pref[2]-pref[2]) = 0. `current_sum` = max(6, 4 + 0 + 6) = 10.
  - Move to index 3: `gap` = -(pref[3]-pref[3]) = 0. `current_sum` = max(8, 10 + 0 + 8) = 18.
- Max diff = 18.

# Complexity
- Time complexity: $$O(M \log M + N)$$, where $M = \max(nums)$. The outer loop runs $M$ times, and the inner loop iterates over multiples of $k$, which is the harmonic series $\sum_{k=1}^M \frac{M}{k} = O(M \log M)$.
- Space complexity: $$O(N + M)$$ to store the prefix sums and the index mapping.

# Code
```cpp
class Solution {
    int mod_mul(int a, int b, int mod) {
        int res = 0;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res + a) % mod;
            }
            a = (a * 2) % mod;
            b /= 2;
        }
        return res;
    }

public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int min_val = nums[0];
        int max_val = nums[0];
        unordered_map<int, vector<int>> val_to_indices;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < min_val) min_val = nums[i];
            if (nums[i] > max_val) max_val = nums[i];
            val_to_indices[nums[i]].push_back(i);
        }
        
        int max_k = max_val > 2 ? max_val : 2;
        
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        int max_diff = -2000000000;
        int best_k = -1;
        
        for (int k = 2; k <= max_k; ++k) {
            vector<int> indices;
            
            for (int v = k; v <= max_val; v += k) {
                if (val_to_indices.count(v)) {
                    for (int idx : val_to_indices[v]) {
                        indices.push_back(idx);
                    }
                }
            }
            
            int diff = 0;
            if (indices.empty()) {
                diff = -min_val;
            } else {
                sort(indices.begin(), indices.end());
                
                int current_max = nums[indices[0]];
                int current_sum = nums[indices[0]];
                
                for (size_t j = 1; j < indices.size(); ++j) {
                    int prev = indices[j - 1];
                    int curr = indices[j];
                    
                    int gap = -(pref[curr] - pref[prev + 1]);
                    int val = nums[curr];
                    
                    current_sum = max(val, current_sum + gap + val);
                    if (current_sum > current_max) {
                        current_max = current_sum;
                    }
                }
                diff = current_max;
            }
            
            if (diff > max_diff) {
                max_diff = diff;
                best_k = k;
            } else if (diff == max_diff) {
                if (k < best_k) {
                    best_k = k;
                }
            }
        }
        
        return mod_mul(max_diff, best_k, 1000000007);
    }
};
```
