# [841. Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `breadth-first-search`, `graph`

---

## Problem Description
There are `n` rooms labeled from `0` to `n - 1` and all the rooms are locked except for room `0`. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of **distinct keys** in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array `rooms` where `rooms[i]` is the set of keys that you can obtain if you visited room `i`, return `true` *if you can visit **all** the rooms, or* `false` *otherwise*.

**Example 1:**

```
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
```

**Example 2:**

```
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
```

**Constraints:**

* `n == rooms.length`
* `2 <= n <= 1000`
* `0 <= rooms[i].length <= 1000`
* `1 <= sum(rooms[i].length) <= 3000`
* `0 <= rooms[i][j] < n`
* All the values of `rooms[i]` are **unique**.

---

## Solution & Editorial
# Intuition
This problem can be modeled as a graph traversal problem where rooms are nodes and the keys inside each room are directed edges pointing to other rooms. Since we start at room 0 and want to determine if all rooms are reachable, standard graph traversal algorithms like Breadth-First Search (BFS) or Depth-First Search (DFS) can be utilized to explore all reachable components.

# Approach
1. Initialize an integer `n` as the total number of rooms using `rooms.size()`.
2. Create a BFS queue `q` to store the rooms to visit and a visited tracking vector `vis` of size `n` initialized to `0`.
3. Push the starting room `0` into the queue `q` and mark `vis[0] = 1`.
4. While the queue `q` is not empty, pop the front room `room` and iterate over all available keys `key` in `rooms[room]`.
5. If a `key` leads to an unvisited room (`vis[key] == 0`), mark it as visited (`vis[key] = 1`) and push it to the queue `q`.
6. After the traversal queue is exhausted, iterate through the `vis` vector. If any room remains unvisited (`x == 0`), return `false`. Otherwise, return `true`.

### Visual Walkthrough for Example 1
`rooms = [[1], [2], [3], []]`

| Step | Queue (`q`) | Current Room | Keys Found | Visited State (`vis`) |
| :--- | :--- | :--- | :--- | :--- |
| Init | `[0]` | - | - | `[1, 0, 0, 0]` |
| 1 | `[1]` | `0` | `1` | `[1, 1, 0, 0]` |
| 2 | `[2]` | `1` | `2` | `[1, 1, 1, 0]` |
| 3 | `[3]` | `2` | `3` | `[1, 1, 1, 1]` |
| 4 | `[]` | `3` | None | `[1, 1, 1, 1]` |

# Complexity
- Time complexity: $$O(N + E)$$ where $$N$$ is the number of rooms and $$E$$ is the total number of keys across all rooms. Each room is added to the queue and visited at most once, and every key in `rooms[i]` is inspected once.
- Space complexity: $$O(N)$$ due to the storage required for the visited vector `vis` and the BFS queue `q` in the worst-case scenario.

# Code
```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int key:rooms[room]){
                if(!vis[key]){
                    vis[key] = 1;
                    q.push(key);
                }
            }
        }

        for(int x:vis){
            if(!x){
                return false;
            }
        }
        return true;
    }
};
```
