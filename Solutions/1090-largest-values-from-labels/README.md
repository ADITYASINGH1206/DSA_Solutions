# [1090. Largest Values From Labels](https://leetcode.com/problems/largest-values-from-labels/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `greedy`, `sorting`, `counting`

---

## Problem Description
You are given `n` item's value and label as two integer arrays `values` and `labels`. You are also given two integers `numWanted` and `useLimit`.

Your task is to find a subset of items with the **maximum sum** of their values such that:

* The number of items is **at most** `numWanted`.
* The number of items with the same label is **at most** `useLimit`.

Return the maximum sum.

**Example 1:**

**Input:** values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1

**Output:** 9

**Explanation:**

The subset chosen is the first, third, and fifth items with the sum of values 5 + 3 + 1.

**Example 2:**

**Input:** values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2

**Output:** 12

**Explanation:**

The subset chosen is the first, second, and third items with the sum of values 5 + 4 + 3.

**Example 3:**

**Input:** values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1

**Output:** 16

**Explanation:**

The subset chosen is the first and fourth items with the sum of values 9 + 7.

**Constraints:**

* `n == values.length == labels.length`
* `1 <= n <= 2 * 104`
* `0 <= values[i], labels[i] <= 2 * 104`
* `1 <= numWanted, useLimit <= n`

---

## Solution & Editorial
# Intuition
To maximize the total sum of chosen items subject to capacity constraints (`numWanted`) and per-label limits (`useLimit`), a greedy strategy is optimal. By always considering the item with the highest available value first, we ensure that we accumulate the largest possible contributions to our total sum.

# Approach
1. Find the maximum label value in `labels` to size our frequency tracker correctly.
2. Push all item pairs `(values[i], labels[i])` into a max-heap priority queue (`pq`) ordered by value descending.
3. Initialize a frequency vector `used` of size `labelmax + 1` filled with `useLimit` to track how many items we can still pick from each label.
4. Greedily pop items from `pq` while `z > 0` (where `z` counts remaining items needed up to `numWanted`).
5. If the current item's label has remaining quota (`used[label] > 0`), add its value to `sum`, decrement `used[label]`, and decrement `z`.
6. Continue until the priority queue is empty or `numWanted` items are selected, then return `sum`.

### Visual Walkthrough (Example 1)
`values = [5, 4, 3, 2, 1]`, `labels = [1, 1, 2, 2, 3]`, `numWanted = 3`, `useLimit = 1`

| Step | Popped `(val, label)` | `used` state for label | Valid? | Action | `sum` | `z` |-
| --- | --- | --- | --- | --- | --- | --- |
| 1 | `(5, 1)` | `used[1]: 1 -> 0` | Yes | Add 5 | `5` | `2` |
| 2 | `(4, 1)` | `used[1]: 0` | No (Limit reached) | Skip | `5` | `2` |
| 3 | `(3, 2)` | `used[2]: 1 -> 0` | Yes | Add 3 | `8` | `1` |
| 4 | `(2, 2)` | `used[2]: 0` | No (Limit reached) | Skip | `8` | `1` |
| 5 | `(1, 3)` | `used[3]: 1 -> 0` | Yes | Add 1 | `9` | `0` |

Final sum returned is `9`.

# Complexity
- Time complexity: $$O(n \log n)$$ — Inserting all $$n$$ elements into the priority queue takes $$O(n \log n)$$ time. Extracting elements takes at most $$O(n \log n)$$ time in the worst case.
- Space complexity: $$O(n + L)$$ — Storing elements in the priority queue requires $$O(n)$$ space, and the `used` array takes $$O(L)$$ space where $$L$$ is the maximum label value.

# Code
```cpp
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int labelmax=0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<values.size();i++){
            pq.push({values[i],labels[i]});
            labelmax=max(labelmax,labels[i]);
        }
        int sum=0;
        int z=numWanted;
        vector<int> used(labelmax+1,useLimit);
        while(!pq.empty() && z>0){
            auto it=pq.top();
            int value=it.first;
            int label=it.second;
            if(used[label]>0){
                sum+=value;
                used[label]--;
                z--;
            }
            pq.pop();
        }
        return sum;
    }
};
```
