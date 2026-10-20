# [1503. Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)
**Difficulty:** `Medium` | **Tags:** `array`, `brainteaser`, `simulation`

---

## Problem Description
We have a wooden plank of the length `n` **units**. Some ants are walking on the plank, each ant moves with a speed of **1 unit per second**. Some of the ants move to the **left**, the other move to the **right**.

When two ants moving in two **different** directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

When an ant reaches **one end** of the plank at a time `t`, it falls out of the plank immediately.

Given an integer `n` and two integer arrays `left` and `right`, the positions of the ants moving to the left and the right, return *the moment when the last ant(s) fall out of the plank*.

**Example 1:**

```
Input: n = 4, left = [4,3], right = [0,1]
Output: 4
Explanation: In the image above:
-The ant at index 0 is named A and going to the right.
-The ant at index 1 is named B and going to the right.
-The ant at index 3 is named C and going to the left.
-The ant at index 4 is named D and going to the left.
The last moment when an ant was on the plank is t = 4 seconds. After that, it falls immediately out of the plank. (i.e., We can say that at t = 4.0000000001, there are no ants on the plank).
```

**Example 2:**

```
Input: n = 7, left = [], right = [0,1,2,3,4,5,6,7]
Output: 7
Explanation: All ants are going to the right, the ant at index 0 needs 7 seconds to fall.
```

**Example 3:**

```
Input: n = 7, left = [0,1,2,3,4,5,6,7], right = []
Output: 7
Explanation: All ants are going to the left, the ant at index 7 needs 7 seconds to fall.
```

**Constraints:**

* `1 <= n <= 104`
* `0 <= left.length <= n + 1`
* `0 <= left[i] <= n`
* `0 <= right.length <= n + 1`
* `0 <= right[i] <= n`
* `1 <= left.length + right.length <= n + 1`
* All values of `left` and `right` are unique, and each value can appear **only in one** of the two arrays.

---

## Solution & Editorial
# Intuition
When two ants collide and change direction, they effectively "pass through" each other because they are identical. The collision does not change the set of trajectories; it only swaps the identities of the ants. Therefore, we can treat each ant as if it continues moving in its original direction until it falls off the plank.

# Approach
1. For an ant moving to the **left** at position `x`, the time taken to fall off is simply `x` seconds (it reaches position 0).
2. For an ant moving to the **right** at position `x`, the time taken to fall off is `n - x` seconds (it reaches position `n`).
3. The total time until the last ant falls is the maximum of these individual times across all ants.
4. We calculate `maxLeft` as the maximum position among all ants in `left`, and `minRight` as the minimum position among all ants in `right` (though the minimum position in `right` actually yields the maximum `n - x` value).

### Visual Trace (Example 1: n=4, left=[4,3], right=[0,1])
| Ant | Direction | Position | Time to Fall |
| :--- | :--- | :--- | :--- |
| A | Right | 0 | 4 - 0 = 4 |
| B | Right | 1 | 4 - 1 = 3 |
| C | Left | 3 | 3 |
| D | Left | 4 | 4 |

- `maxLeft` = max(4, 3) = 4
- `n - minRight` = 4 - min(0, 1) = 4 - 0 = 4
- Result = max(4, 4) = 4

# Complexity
- Time complexity: $$O(L + R)$$, where $$L$$ and $$R$$ are the lengths of the `left` and `right` arrays respectively. We perform a single pass over each array to find the extremum.
- Space complexity: $$O(1)$$, as we only store a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
    
        return max(maxLeft, n - minRight);
    }
};
```
