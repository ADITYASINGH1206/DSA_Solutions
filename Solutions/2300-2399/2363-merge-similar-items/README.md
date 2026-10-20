# [2363. Merge Similar Items](https://leetcode.com/problems/merge-similar-items/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `ordered-set`

---

## Problem Description
You are given two 2D integer arrays, `items1` and `items2`, representing two sets of items. Each array `items` has the following properties:

* `items[i] = [valuei, weighti]` where `valuei` represents the **value** and `weighti` represents the **weight** of the `ith` item.
* The value of each item in `items` is **unique**.

Return *a 2D integer array* `ret` *where* `ret[i] = [valuei, weighti]`*,* *with* `weighti` *being the **sum of weights** of all items with value* `valuei`.

**Note:** `ret` should be returned in **ascending** order by value.

**Example 1:**

```
Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
Output: [[1,6],[3,9],[4,5]]
Explanation: 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
Therefore, we return [[1,6],[3,9],[4,5]].
```

**Example 2:**

```
Input: items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
Output: [[1,4],[2,4],[3,4]]
Explanation: 
The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 3, total weight = 1 + 3 = 4.
The item with value = 2 occurs in items1 with weight = 3 and in items2 with weight = 1, total weight = 3 + 1 = 4.
The item with value = 3 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4.
Therefore, we return [[1,4],[2,4],[3,4]].
```

**Example 3:**

```
Input: items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
Output: [[1,7],[2,4],[7,1]]
Explanation:
The item with value = 1 occurs in items1 with weight = 3 and in items2 with weight = 4, total weight = 3 + 4 = 7. 
The item with value = 2 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4. 
The item with value = 7 occurs in items2 with weight = 1, total weight = 1.
Therefore, we return [[1,7],[2,4],[7,1]].
```

**Constraints:**

* `1 <= items1.length, items2.length <= 1000`
* `items1[i].length == items2[i].length == 2`
* `1 <= valuei, weighti <= 1000`
* Each `valuei` in `items1` is **unique**.
* Each `valuei` in `items2` is **unique**.

---

## Solution & Editorial
# Intuition
To merge two sets of items while maintaining ascending order, we can leverage the properties of sorted arrays. By sorting both input arrays by their value, we can efficiently merge them using a two-pointer approach, similar to the merge step in Merge Sort.

# Approach
1. Sort `items1` and `items2` based on the item value (index 0) in ascending order.
2. Initialize two pointers `i` and `j` at the start of `items1` and `items2` respectively.
3. Iterate while both pointers are within bounds:
   - If values are equal, add the sum of weights to `ans` and increment both pointers.
   - If the value in `items1` is smaller, add the current `items1` element to `ans` and increment `i`.
   - If the value in `items2` is smaller, add the current `items2` element to `ans` and increment `j`.
4. Append any remaining elements from either array to `ans`.

### Visual Trace (Example 1)
`items1 = [[1,1],[3,8],[4,5]]`, `items2 = [[1,5],[3,1]]`

| Step | i | j | items1[i] | items2[j] | Action | ans |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | [1,1] | [1,5] | Match | [[1,6]] |
| 2 | 1 | 1 | [3,8] | [3,1] | Match | [[1,6],[3,9]] |
| 3 | 2 | 2 | [4,5] | - | Exhaust j | [[1,6],[3,9],[4,5]] |

# Complexity
- Time complexity: $$O(N \log N + M \log M)$$, where $$N$$ and $$M$$ are the lengths of `items1` and `items2`. Sorting dominates the complexity, while the two-pointer merge is linear $$O(N+M)$$.
- Space complexity: $$O(N + M)$$ to store the resulting merged array.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        sort(items1.begin(), items1.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        sort(items2.begin(), items2.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        
        int m = items1.size();
        int n = items2.size();
        int i = 0,j=0;
        while(i<m && j<n){
            if(items1[i][0] == items2[j][0]) {
                ans.push_back({items1[i][0],items1[i][1]+items2[j][1]});
                i++,j++;
            }
            else if(items1[i][0] > items2[j][0]){
                ans.push_back({items2[j][0],items2[j][1]});
                j++;
            }else{
                ans.push_back({items1[i][0],items1[i][1]});
                i++;
            }
        }
        while(i<m){
            ans.push_back({items1[i][0],items1[i][1]});
            i++;
        }
        while(j<n){
            ans.push_back({items2[j][0],items2[j][1]});
            j++;
        }

        return ans;
    }
};
```
