# [735. Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `simulation`

---

## Problem Description
We are given an array `asteroids` of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

**Example 1:**

```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

**Example 2:**

```
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

**Example 3:**

```
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

**Example 4:**

```
Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.
```

**Constraints:**

* `2 <= asteroids.length <= 104`
* `-1000 <= asteroids[i] <= 1000`
* `asteroids[i] != 0`

---

## Solution & Editorial
# Intuition
The problem asks us to simulate collisions between moving asteroids. Collisions only occur when a moving-right asteroid (`> 0`) is followed by a moving-left asteroid (`< 0`). A stack data structure is ideal for tracking active moving-right asteroids that may collide with incoming left-moving asteroids.

# Approach
1. Initialize an empty vector `st` to act as a stack holding the surviving asteroids.
2. Iterate through each asteroid in the input array `asteroids` using index `i`.
3. If `asteroids[i]` is positive, push it directly to `st` since it moves right and cannot collide with previously processed asteroids.
4. If `asteroids[i]` is negative, handle potential collisions with the top of the stack:
   - While the stack is not empty, the top of the stack moves right (`st.back() > 0`), and the incoming left asteroid's magnitude exceeds the top (`abs(asteroids[i]) > st.back()`), pop the smaller asteroid from the stack.
   - If the stack is not empty and the top equals the incoming asteroid's magnitude (`st.back() == abs(asteroids[i])`), both explode, so pop the stack and discard the current incoming asteroid.
   - If the top of the stack is larger than the incoming asteroid's magnitude (`st.back() > abs(asteroids[i])`), the incoming asteroid explodes and we continue.
   - If the stack becomes empty or the top of the stack also moves left (`st.back() < 0`), the incoming asteroid survives and is pushed onto the stack.
5. Return the resulting vector `st`.

### Visual Dry Run (Example 1: `asteroids = [5, 10, -5]`)

| Step | Asteroid | Stack State (`st`) | Action | Description |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `5` | `[5]` | Push | Positive asteroid pushed. |
| 2 | `10` | `[5, 10]` | Push | Positive asteroid pushed. |
| 3 | `-5` | `[5, 10]` | Collide | `-5` collides with `10`. Since `10 > 5`, `-5` explodes, `10` survives. |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of asteroids. Each asteroid is pushed onto and popped from the stack at most once.
- Space complexity: $$O(N)$$ to store the stack of surviving asteroids in the worst case.

# Code
```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();
        for(int i = 0;i<n;i++){
            if(asteroids[i] >0) st.push_back(asteroids[i]);
            else{
                while(!st.empty()&& st.back() > 0 && abs(asteroids[i]) > st.back()){
                    st.pop_back();
                }
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }
                else if(!st.empty() && st.back() > abs(asteroids[i])) continue;
                else if(st.empty()  || st.back() <0){
                    st.push_back(asteroids[i]);
                }
            }

        }
        return st;

    }
};
```
