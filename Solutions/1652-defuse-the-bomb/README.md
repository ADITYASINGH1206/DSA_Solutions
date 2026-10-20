# [1652. Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/)
**Difficulty:** `Easy` | **Tags:** `array`, `sliding-window`

---

## Problem Description
You have a bomb to defuse, and your time is running out! Your informer will provide you with a **circular** array `code` of length of `n` and a key `k`.

To decrypt the code, you must replace every number. All the numbers are replaced **simultaneously**.

* If `k > 0`, replace the `ith` number with the sum of the **next** `k` numbers.
* If `k < 0`, replace the `ith` number with the sum of the **previous** -`k` numbers.
* If `k == 0`, replace the `ith` number with `0`.

As `code` is circular, the next element of `code[n-1]` is `code[0]`, and the previous element of `code[0]` is `code[n-1]`.

Given the **circular** array `code` and an integer key `k`, return *the decrypted code to defuse the bomb*!

**Example 1:**

```
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
```

**Example 2:**

```
Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0.
```

**Example 3:**

```
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
```

**Constraints:**

* `n == code.length`
* `1 <= n <= 100`
* `1 <= code[i] <= 100`
* `-(n - 1) <= k <= n - 1`

---

## Solution & Editorial
# Intuition
The problem requires us to compute a sliding window sum over a circular array. Since the array is circular, we can map any index to the range `[0, n-1]` using the modulo operator. The core observation is that for any index `i`, we simply need to sum the next `k` elements (if `k > 0`) or the previous `|k|` elements (if `k < 0`) while wrapping around the array boundaries.

# Approach
1. Initialize a result vector `ans` of size `n` with zeros. If `k == 0`, return this vector immediately.
2. If `k > 0`, iterate through each index `i` from `0` to `n-1`. For each `i`, calculate the sum of the next `k` elements by iterating `j` from `0` to `k-1`. Use `(i + 1 + j) % n` to handle the circular wrap-around.
3. If `k < 0`, iterate through each index `i` from `0` to `n-1`. For each `i`, calculate the sum of the previous `|k|` elements by iterating `j` from `1` to `|k|`. Use `(i - j + n) % n` to handle the circular wrap-around correctly for negative indices.

### Visual Trace (Example 1: code = [5, 7, 1, 4], k = 3)
| i | Window (next 3) | Sum | ans[i] |
|---|---|---|---|
| 0 | 7, 1, 4 | 7+1+4 | 12 |
| 1 | 1, 4, 5 | 1+4+5 | 10 |
| 2 | 4, 5, 7 | 4+5+7 | 16 |
| 3 | 5, 7, 1 | 5+7+1 | 13 |

# Complexity
- Time complexity: $$O(n \cdot |k|)$$, where $$n$$ is the length of the array. We iterate through each of the $$n$$ elements, and for each, we perform $$|k|$$ additions.
- Space complexity: $$O(n)$$ to store the result vector `ans`.

# Code
```cpp
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        int count = 0;
        if(k == 0) return ans;
        if(k>0){
            for(int i = 0;i<n;i++){
                int temp = 0;
                for(int j= 0;j<k;j++){
                    int idx = (i+1+j)%n;
                    temp += code[idx];
                }
                ans[i] = temp;
            }
        }
        else{
            int absk = abs(k);
            for(int i = 0;i<n;i++){
                int temp = 0;
                for(int j= 1;j<=absk;j++){
                    int idx =(i-j+n)%n;
                    temp += code[idx];
                }
                ans[i] = temp;
            }
        }




        return ans;
    }
};
```
