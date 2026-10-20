# [1817. Finding the Users Active Minutes](https://leetcode.com/problems/finding-the-users-active-minutes/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given the logs for users' actions on LeetCode, and an integer `k`. The logs are represented by a 2D integer array `logs` where each `logs[i] = [IDi, timei]` indicates that the user with `IDi` performed an action at the minute `timei`.

**Multiple users** can perform actions simultaneously, and a single user can perform **multiple actions** in the same minute.

The **user active minutes (UAM)** for a given user is defined as the **number of unique minutes** in which the user performed an action on LeetCode. A minute can only be counted once, even if multiple actions occur during it.

You are to calculate a **1-indexed** array `answer` of size `k` such that, for each `j` (`1 <= j <= k`), `answer[j]` is the **number of users** whose **UAM** equals `j`.

Return *the array* `answer` *as described above*.

**Example 1:**

```
Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
Output: [0,2,0,0,0]
Explanation:
The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 (minute 5 is only counted once).
The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
Since both users have a UAM of 2, answer[2] is 2, and the remaining answer[j] values are 0.
```

**Example 2:**

```
Input: logs = [[1,1],[2,2],[2,3]], k = 4
Output: [1,1,0,0]
Explanation:
The user with ID=1 performed a single action at minute 1. Hence, they have a UAM of 1.
The user with ID=2 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
There is one user with a UAM of 1 and one with a UAM of 2.
Hence, answer[1] = 1, answer[2] = 1, and the remaining values are 0.
```

**Constraints:**

* `1 <= logs.length <= 104`
* `0 <= IDi <= 109`
* `1 <= timei <= 105`
* `k` is in the range `[The maximum UAM for a user, 105]`.

---

## Solution & Editorial
# Intuition
To calculate the User Active Minutes (UAM) for each user, we need to track the unique timestamps associated with each user ID. Since a user can perform multiple actions in the same minute, a `std::unordered_set` is the ideal data structure to store unique minutes per user. By mapping each user ID to their set of unique minutes, we can easily determine their UAM by checking the size of the set.

# Approach
1. Initialize an `unordered_map<int, unordered_set<int>>` named `m` to store the mapping from user ID to a set of unique timestamps.
2. Iterate through the `logs` array. For each log entry `[ID, time]`, insert the `time` into the set corresponding to the `ID` in map `m`.
3. Initialize a result vector `res` of size `k` with zeros.
4. Iterate through the map `m`. For each entry, retrieve the size of the `unordered_set` (which represents the UAM for that user). Increment the corresponding index in `res` (using `size - 1` to account for 0-indexing).

### Visual Trace (Example 1)
`logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5`

| Step | Map State (`m`) | UAM Calculation |
| :--- | :--- | :--- |
| Process [0,5] | {0: {5}} | - |
| Process [1,2] | {0: {5}, 1: {2}} | - |
| Process [0,2] | {0: {5, 2}, 1: {2}} | - |
| Process [0,5] | {0: {5, 2}, 1: {2}} | - |
| Process [1,3] | {0: {5, 2}, 1: {2, 3}} | - |
| Finalize | - | User 0: size 2, User 1: size 2 |

Result: `res[2-1]++` twice -> `[0, 2, 0, 0, 0]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of logs. We iterate through the logs once to populate the map, and then iterate through the map entries, which is at most $$N$$.
- Space complexity: $$O(N)$$, as we store each unique log entry in the hash map and set structure.

# Code
```cpp
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> res(k);
        for (auto &l : logs)
            m[l[0]].insert(l[1]);
        for (auto &p : m)
            ++res[p.second.size() - 1];
        return res;
    }
};
```
