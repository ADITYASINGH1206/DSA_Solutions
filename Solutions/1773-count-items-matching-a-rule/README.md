# [1773. Count Items Matching a Rule](https://leetcode.com/problems/count-items-matching-a-rule/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given an array `items`, where each `items[i] = [typei, colori, namei]` describes the type, color, and name of the `ith` item. You are also given a rule represented by two strings, `ruleKey` and `ruleValue`.

The `ith` item is said to match the rule if **one** of the following is true:

* `ruleKey == "type"` and `ruleValue == typei`.
* `ruleKey == "color"` and `ruleValue == colori`.
* `ruleKey == "name"` and `ruleValue == namei`.

Return *the number of items that match the given rule*.

**Example 1:**

```
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
```

**Example 2:**

```
Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
```

**Constraints:**

* `1 <= items.length <= 104`
* `1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10`
* `ruleKey` is equal to either `"type"`, `"color"`, or `"name"`.
* All strings consist only of lowercase letters.

---

## Solution & Editorial
# Intuition
The problem asks us to filter a list of items based on a dynamic key. Since each item has a fixed structure (type, color, name), we can map the `ruleKey` to a specific index (0, 1, or 2) and perform a single pass over the input array to count matches.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each item in the `items` vector.
3. Check the `ruleKey` string:
   - If `ruleKey` is "type", compare `ruleValue` with `items[i][0]`.
   - If `ruleKey` is "color", compare `ruleValue` with `items[i][1]`.
   - If `ruleKey` is "name", compare `ruleValue` with `items[i][2]`.
4. Increment `ans` whenever a match is found.

### Visual Trace (Example 1)
`items = [["phone","blue","pixel"], ["computer","silver","lenovo"], ["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"`

| Iteration | Item | Index Checked | Value | Match? | `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | ["phone","blue","pixel"] | 1 | "blue" | No | 0 |
| 1 | ["computer","silver","lenovo"] | 1 | "silver" | Yes | 1 |
| 2 | ["phone","gold","iphone"] | 1 | "gold" | No | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of items. We perform a single linear scan through the input array, and string comparisons take constant time since the string lengths are capped at 10.
- Space complexity: $$O(1)$$, as we only use a single integer variable `ans` for counting, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0;
        for(int i=0;i<items.size();i++){
            if(ruleKey == "type"){
                if(items[i][0] == ruleValue) ans++;
            }else if(ruleKey == "color"){
                if(items[i][1] == ruleValue) ans++;
            }else if(ruleKey == "name"){
                if(items[i][2] == ruleValue) ans++;
            }
        }
        return ans;
    }
};
```
