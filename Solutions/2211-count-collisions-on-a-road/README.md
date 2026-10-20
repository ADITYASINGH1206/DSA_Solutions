# [2211. Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `simulation`

---

## Problem Description
There are `n` cars on an infinitely long road. The cars are numbered from `0` to `n - 1` from left to right and each car is present at a **unique** point.

You are given a **0-indexed** string `directions` of length `n`. `directions[i]` can be either `'L'`, `'R'`, or `'S'` denoting whether the `ith` car is moving towards the **left**, towards the **right**, or **staying** at its current point respectively. Each moving car has the **same speed**.

The number of collisions can be calculated as follows:

* When two cars moving in **opposite** directions collide with each other, the number of collisions increases by `2`.
* When a moving car collides with a stationary car, the number of collisions increases by `1`.

After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Return *the **total number of collisions** that will happen on the road*.

**Example 1:**

```
Input: directions = "RLRSLL"
Output: 5
Explanation:
The collisions that will happen on the road are:
- Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
- Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
- Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
- Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
Thus, the total number of collisions that will happen on the road is 5.
```

**Example 2:**

```
Input: directions = "LLRR"
Output: 0
Explanation:
No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.
```

**Constraints:**

* `1 <= directions.length <= 105`
* `directions[i]` is either `'L'`, `'R'`, or `'S'`.

---

## Solution & Editorial
# Intuition
Any car moving 'L' at the very beginning of the string will never collide with anything, as there are no cars to its left. Similarly, any car moving 'R' at the very end of the string will never collide with anything, as there are no cars to its right. Once we trim these "harmless" cars, every remaining car will eventually collide. 

# Approach
1. Use two pointers, `left` and `right`, to identify the range of cars that will definitely be involved in a collision.
2. Increment `left` while `directions[left] == 'L'` to skip cars moving left that have no cars to their left to hit.
3. Decrement `right` while `directions[right] == 'R'` to skip cars moving right that have no cars to their right to hit.
4. Any car remaining in the range `[left, right]` that is not stationary ('S') will eventually collide. Since every collision involving an 'R' or 'L' car results in either a stationary car or another collision, we simply count all non-'S' cars in this range.

### Visual Trace: "RLRSLL"
- Initial: `L=0, R=5`, `directions="RLRSLL"`
- Trim `L`: `directions[0]` is 'R', so `left` stays 0.
- Trim `R`: `directions[5]` is 'L', so `right` stays 5.
- Loop `i` from 0 to 5:
  - `i=0 ('R')`: `ans` becomes 1
  - `i=1 ('L')`: `ans` becomes 2
  - `i=2 ('R')`: `ans` becomes 3
  - `i=3 ('S')`: `ans` stays 3
  - `i=4 ('L')`: `ans` becomes 4
  - `i=5 ('L')`: `ans` becomes 5
- Result: 5

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass to trim the pointers and a single pass to count the collisions.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0;
        int right = n - 1;
        
        while (left < n && directions[left] == 'L') {
            left++;
        }
        
        while (right >= 0 && directions[right] == 'R') {
            right--;
        }
        
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                ans++;
            }
        }
        
        return ans;
    }
};
```
