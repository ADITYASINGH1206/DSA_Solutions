# [4053. Minimum Operations to Make Every Element Palindromic](https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`

---

## Problem Description
You are given an integer array `nums`.

In one **operation**, you may choose an index `i` and either increment or decrement `nums[i]` by 2.

Return the **minimum** number of operations required to make every element in `nums` a **positive** palindrome. Different elements may be changed into different palindromic integers.

**Example 1:**

**Input:** nums = [10,12,14,16]

**Output:** 9

**Explanation:**

One optimal sequence of operations is:

* Decrement `nums[0]` by 2 once to change it from 10 to 8.
* Decrement `nums[1]` by 2 twice to change it from 12 to 8.
* Decrement `nums[2]` by 2 three times to change it from 14 to 8.
* Increment `nums[3]` by 2 three times to change it from 16 to 22.

After `1 + 2 + 3 + 3 = 9` operations, `nums = [8, 8, 8, 22]`, and every element is a positive palindromic integer.

It can be shown that fewer than 9 operations cannot achieve this.

**Example 2:**

**Input:** nums = [9,10,11,10]

**Output:** 2

**Explanation:**

Decrement `nums[1]` and `nums[3]` by 2 once each.

After 2 operations, `nums = [9, 8, 11, 8]`, and every element is a positive palindromic integer.

At least one operation is needed for each of these two elements, so the minimum number of operations is 2.

**Example 3:**

**Input:** nums = [125]

**Output:** 2

**Explanation:**

Decrement `nums[0]` by 2 twice to change it from 125 to 121, which is a positive palindromic integer.

A single operation would change it to 123 or 127, neither of which is palindromic. Thus, the minimum number of operations is 2.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
Since we can only increment or decrement by 2, the parity of each number is invariant. A number `x` can only be transformed into a palindrome `p` if `x % 2 == p % 2`. We precompute all palindromes up to a sufficient range, categorize them by parity, and for each input number, perform a binary search to find the closest reachable palindrome.

# Approach
1. **Precomputation**: Generate all palindromes up to 10^9. A palindrome is formed by taking a number `i` and mirroring it (e.g., `123` becomes `12321` or `123321`). We store these in two sorted vectors, `even` and `odd`, based on their parity.
2. **Binary Search**: For each `x` in `nums`, identify the target parity vector. Use `std::lower_bound` to find the smallest palindrome `p >= x`. 
3. **Calculation**: The closest palindrome is either the one found by `lower_bound` or the one immediately preceding it. Calculate the absolute difference, divide by 2 (since operations are in steps of 2), and accumulate the result.

### Visual Trace (Example 1: nums = [10, 12, 14, 16])
- Parity of all is even. Closest even palindromes are 8, 11 (odd), 22, etc.
- `10`: `lower_bound` finds 22, `it-1` is 8. `abs(8-10)/2 = 1`.
- `12`: `lower_bound` finds 22, `it-1` is 8. `abs(8-12)/2 = 2`.
- `14`: `lower_bound` finds 22, `it-1` is 8. `abs(8-14)/2 = 3`.
- `16`: `lower_bound` finds 22, `it-1` is 8. `abs(22-16)/2 = 3`.
- Total: `1 + 2 + 3 + 3 = 9`.

# Complexity
- Time complexity: $$O(M \log M + N \log M)$$, where $$M$$ is the number of precomputed palindromes (~2*10^5) and $$N$$ is the length of `nums`. Sorting takes $$O(M \log M)$$, and each of the $$N$$ queries takes $$O(\log M)$$.
- Space complexity: $$O(M)$$, required to store the precomputed palindromes in the `even` and `odd` vectors.

# Code
```cpp
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        static vector<long long> even;
        static vector<long long> odd;
        static bool in = false;
        if (!in) {
            for (int i = 1; i < 100000; i++) {
                long long p1 = i, p2 = i;
                long long t1 = i / 10, t2 = i;
                while (t1 > 0) { 
                    p1 = p1 * 10 + (t1 % 10); 
                    t1 /= 10; 
                }
                while (t2 > 0) { 
                    p2 = p2 * 10 + (t2 % 10); 
                    t2 /= 10; 
                }
                
                if (p1 % 2 == 0) even.push_back(p1); else odd.push_back(p1);
                if (p2 % 2 == 0) even.push_back(p2); else odd.push_back(p2);
            }
            
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            in = true;
        }
        
        long long ans = 0;
        for (long long x : nums) {
            const vector<long long>& pals = (x % 2 == 0) ? even : odd;
            
            auto it = lower_bound(pals.begin(), pals.end(), x);
            long long diff = LLONG_MAX;

            if (it != pals.end()) {
                diff = min(diff, abs(*it - x));
            }
            if (it != pals.begin()) {
                diff = min(diff, abs(*(it - 1) - x));
            }
            
            ans += diff / 2;
        }
        
        return ans;
    }
};
```
