# [3668. Restore Finishing Order](https://leetcode.com/problems/restore-finishing-order/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `order` of length `n` and an integer array `friends`.

* `order` contains every integer from 1 to `n` **exactly once**, representing the IDs of the participants of a race in their **finishing** order.
* `friends` contains the IDs of your friends in the race **sorted** in strictly increasing order. Each ID in friends is guaranteed to appear in the `order` array.

Return an array containing your friends' IDs in their **finishing** order.

**Example 1:**

**Input:** order = [3,1,2,5,4], friends = [1,3,4]

**Output:** [3,1,4]

**Explanation:**

The finishing order is `[3, 1, 2, 5, 4]`. Therefore, the finishing order of your friends is `[3, 1, 4]`.

**Example 2:**

**Input:** order = [1,4,5,3,2], friends = [2,5]

**Output:** [5,2]

**Explanation:**

The finishing order is `[1, 4, 5, 3, 2]`. Therefore, the finishing order of your friends is `[5, 2]`.

**Constraints:**

* `1 <= n == order.length <= 100`
* `order` contains every integer from 1 to `n` exactly once
* `1 <= friends.length <= min(8, n)`
* `1 <= friends[i] <= n`
* `friends` is strictly increasing

---

## Solution & Editorial
# Intuition
The problem asks us to filter the `order` array to only include elements present in the `friends` array, while preserving their relative order from the original `order` array. Since the `order` array already represents the finishing sequence, we simply need to iterate through it and check if each participant is one of our friends.

# Approach
1. Initialize an empty vector `ans` to store the result.
2. Iterate through each element `order[i]` in the `order` array.
3. For each `order[i]`, iterate through the `friends` array to check if `order[i]` exists within it.
4. If a match is found, append `order[i]` to `ans` and break the inner loop to move to the next participant in the `order` array.
5. Return `ans`.

### Visual Trace (Example 1: order = [3,1,2,5,4], friends = [1,3,4])
| Step | order[i] | friends check | Match? | ans |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 3 | 3 == 1? No, 3 == 3? Yes | Yes | [3] |
| 2 | 1 | 1 == 1? Yes | Yes | [3, 1] |
| 3 | 2 | 2 == 1? No, 2 == 3? No, 2 == 4? No | No | [3, 1] |
| 4 | 5 | 5 == 1? No, 5 == 3? No, 5 == 4? No | No | [3, 1] |
| 5 | 4 | 4 == 1? No, 4 == 3? No, 4 == 4? Yes | Yes | [3, 1, 4] |

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ is the length of `order` and $$M$$ is the length of `friends`. We perform a nested loop where for each of the $$N$$ elements, we potentially scan all $$M$$ elements of the `friends` array.
- Space complexity: $$O(M)$$, as the result vector `ans` stores exactly the number of friends present in the race.

# Code
```cpp
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        for (int i=0;i<order.size();i++){
            for(int j=0;j<friends.size();j++){
                if(order[i] == friends[j]){
                    ans.push_back(order[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```
