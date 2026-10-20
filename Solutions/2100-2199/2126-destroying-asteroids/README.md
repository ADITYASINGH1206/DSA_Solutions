# [2126. Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer `mass`, which represents the original mass of a planet. You are further given an integer array `asteroids`, where `asteroids[i]` is the mass of the `ith` asteroid.

You can arrange for the planet to collide with the asteroids in **any arbitrary order**. If the mass of the planet is **greater than or equal to** the mass of the asteroid, the asteroid is **destroyed** and the planet **gains** the mass of the asteroid. Otherwise, the planet is destroyed.

Return `true` *if **all** asteroids can be destroyed. Otherwise, return* `false`*.*

**Example 1:**

```
Input: mass = 10, asteroids = [3,9,19,5,21]
Output: true
Explanation: One way to order the asteroids is [9,19,5,3,21]:
- The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
- The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
- The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
- The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
- The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
All asteroids are destroyed.
```

**Example 2:**

```
Input: mass = 5, asteroids = [4,9,23,4]
Output: false
Explanation: 
The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
This is less than 23, so a collision would not destroy the last asteroid.
```

**Constraints:**

* `1 <= mass <= 105`
* `1 <= asteroids.length <= 105`
* `1 <= asteroids[i] <= 105`

---

## Solution & Editorial
# Intuition
To maximize the planet's chances of destroying all asteroids, we should always attempt to destroy the smallest available asteroids first. By consuming smaller asteroids, the planet increases its mass, making it easier to destroy larger ones later. This greedy strategy is optimal because if the planet cannot destroy the smallest remaining asteroid, it will never be able to destroy any larger ones.

# Approach
1. Sort the `asteroids` array in non-decreasing order. This ensures we always process the lightest asteroids first.
2. Use a `long long` variable `m` to track the current mass of the planet. We use `long long` to prevent potential integer overflow when summing asteroid masses.
3. Iterate through the sorted `asteroids` array:
   - If the current planet mass `m` is less than the asteroid mass `x`, it is impossible to destroy this asteroid (and all subsequent, larger ones), so return `false`.
   - Otherwise, add the asteroid's mass `x` to `m` and continue.
4. If the loop completes, all asteroids have been successfully destroyed; return `true`.

### Visual Trace (Example 1: mass = 10, asteroids = [3, 9, 19, 5, 21])
Sorted: `[3, 5, 9, 19, 21]`

| Step | Current Mass (m) | Asteroid (x) | Condition (m >= x) | New Mass |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 10 | 3 | 10 >= 3 (True) | 13 |
| 2 | 13 | 5 | 13 >= 5 (True) | 18 |
| 3 | 18 | 9 | 18 >= 9 (True) | 27 |
| 4 | 27 | 19 | 27 >= 19 (True) | 46 |
| 5 | 46 | 21 | 46 >= 21 (True) | 67 |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of asteroids. The dominant operation is sorting the array.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we only use a single variable to track the planet's mass.

# Code
```cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        for (int x : asteroids) {
            if (m < x) {
                return false;
            }
            m += x;
        }
        return true;
    }
};
```
