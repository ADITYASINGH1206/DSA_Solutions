# [1598. Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `stack`

---

## Problem Description
The Leetcode file system keeps a log each time some user performs a *change folder* operation.

The operations are described below:

* `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, **remain in the same folder**).
* `"./"` : Remain in the same folder.
* `"x/"` : Move to the child folder named `x` (This folder is **guaranteed to always exist**).

You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in `logs` are performed.

Return *the minimum number of operations needed to go back to the main folder after the change folder operations.*

**Example 1:**

```
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```

**Example 2:**

```
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```

**Example 3:**

```
Input: logs = ["d1/","../","../","../"]
Output: 0
```

**Constraints:**

* `1 <= logs.length <= 103`
* `2 <= logs[i].length <= 10`
* `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.
* `logs[i]` follows the format described in the statement.
* Folder names consist of lowercase English letters and digits.

---

## Solution & Editorial
# Intuition
The problem asks for the depth of the current directory relative to the root. Since we only care about the net depth, we can maintain a simple integer counter representing the current folder level, rather than simulating the entire file system structure.

# Approach
1. Initialize an integer `ans` to 0, representing the current depth from the main folder.
2. Iterate through each string `logs[i]` in the input vector:
   - If `logs[i]` is "../", we move to the parent folder. If `ans > 0`, decrement `ans` to reflect moving up. If `ans` is 0, we are already at the root, so we do nothing.
   - If `logs[i]` is "./", we remain in the current folder, so we do nothing.
   - Otherwise, we are entering a child folder, so we increment `ans`.
3. After processing all logs, `ans` represents the number of steps required to return to the root.

### Visual Trace (Example 1: logs = ["d1/", "d2/", "../", "d21/", "./"])
| Step | Operation | `ans` (Depth) |
| :--- | :--- | :--- |
| Start | - | 0 |
| 1 | "d1/" | 1 |
| 2 | "d2/" | 2 |
| 3 | "../" | 1 |
| 4 | "d21/" | 2 |
| 5 | "./" | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of logs. We iterate through the list exactly once, performing constant-time string comparisons and arithmetic operations.
- Space complexity: $$O(1)$$, as we only use a single integer variable `ans` to track the depth, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        int n = logs.size();
        for(int i = 0;i<n;i++){
            if(logs[i] == "../"){
                if(ans>0) ans--;
            }
            else if(logs[i] == "./") continue;
            else{
                ans++;
            }
        }

        return ans;
    }
};
```
