# [1233. Remove Sub-Folders from the Filesystem](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `depth-first-search`, `trie`

---

## Problem Description
Given a list of folders `folder`, return *the folders after removing all **sub-folders** in those folders*. You may return the answer in **any order**.

If a `folder[i]` is located within another `folder[j]`, it is called a **sub-folder** of it. A sub-folder of `folder[j]` must start with `folder[j]`, followed by a `"/"`. For example, `"/a/b"` is a sub-folder of `"/a"`, but `"/b"` is not a sub-folder of `"/a/b/c"`.

The format of a path is one or more concatenated strings of the form: `'/'` followed by one or more lowercase English letters.

* For example, `"/leetcode"` and `"/leetcode/problems"` are valid paths while an empty string and `"/"` are not.

**Example 1:**

```
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
```

**Example 2:**

```
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
```

**Example 3:**

```
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]
```

**Constraints:**

* `1 <= folder.length <= 4 * 104`
* `2 <= folder[i].length <= 100`
* `folder[i]` contains only lowercase letters and `'/'`.
* `folder[i]` always starts with the character `'/'`.
* Each folder name is **unique**.

---

## Solution & Editorial
# Intuition
By sorting the list of folder paths lexicographically, any potential parent folder will always appear immediately before its sub-folders. This property allows us to maintain a single resultant collection and check each incoming folder against only the most recently added folder to detect and filter out sub-folders.

# Approach
1. Sort the `folder` vector lexicographically using `std::sort`. Lexicographical ordering guarantees that a prefix path like `"/a"` comes before its extensions like `"/a/b"` or `"/a/b/c"`.
2. Initialize an empty `vector<string> ans` to store the non-sub-folder paths.
3. Iterate through each string `f` in the sorted `folder` vector:
   - If `ans` is empty, push `f` directly into `ans`.
   - Otherwise, retrieve the last added folder `prev = ans.back()`.
   - Check if `f` is a sub-folder of `prev`: verify that `f`'s length is greater than `prev`'s length, the prefix of `f` of length `prev.size()` matches `prev`, and the character immediately following the prefix in `f` is `'/'`.
   - If all conditions are met, `f` is a sub-folder, so we skip it (`continue`). Otherwise, we add `f` to `ans` as a new base folder.
4. Return `ans`.

### Visual Trace Walkthrough (Example 1)
Input: `folder = ["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]`
Sorted: `["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]`

| Iteration | Current Folder (`f`) | `ans.back()` (`prev`) | Condition Check (`f` starts with `prev + '/'`) | Action Taken | `ans` State |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `"/a"` | (empty) | `ans.empty()` is true | Push `"/a"` | `["/a"]` |
| 2 | `"/a/b"` | `"/a"` | `"/a/b".substr(0, 2) == "/a"` and `"/a/b"[2] == '/'` (True) | Skip (`continue`) | `["/a"]` |
| 3 | `"/c/d"` | `"/a"` | Prefix match fails (False) | Push `"/c/d"` | `["/a", "/c/d"]` |
| 4 | `"/c/d/e"` | `"/c/d"` | Prefix match and `'/'` follow check succeed (True) | Skip (`continue`) | `["/a", "/c/d"]` |
| 5 | `"/c/f"` | `"/c/d"` | Prefix match fails (False) | Push `"/c/f"` | `["/a", "/c/d", "/c/f"]` |

# Complexity
- Time complexity: $$O(N \log N \cdot L)$$ — Sorting $$N$$ strings of maximum length $$L$$ takes $$O(N \log N \cdot L)$$ time. The subsequent linear scan takes $$O(N \cdot L)$$ time for substring checks. Thus, overall time complexity is dominated by the sorting step.
- Space complexity: $$O(N \cdot L)$$ — Auxiliary space required for storing the output vector and standard string operations during sorting.

# Code
```cpp
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (auto f : folder) {
            if (ans.empty()) {
                ans.push_back(f);
            } else {
                string& prev = ans.back();
                if(f.size()>prev.size() && f.substr(0,prev.size()) == prev && f.substr(prev.size(),1) == "/"){
                    continue;
                }else{
                    ans.push_back(f);
                }
            }
        }
        return ans;
    }
};
```
