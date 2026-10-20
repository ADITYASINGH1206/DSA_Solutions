# [1409. Queries on a Permutation With Key](https://leetcode.com/problems/queries-on-a-permutation-with-key/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-indexed-tree`, `simulation`, `sqrt-decomposition`

---

## Problem Description
Given the array `queries` of positive integers between `1` and `m`, you have to process all `queries[i]` (from `i=0` to `i=queries.length-1`) according to the following rules:

* In the beginning, you have the permutation `P=[1,2,3,...,m]`.
* For the current `i`, find the position of `queries[i]` in the permutation `P` (**indexing from 0**) and then move this at the beginning of the permutation `P`. Notice that the position of `queries[i]` in `P` is the result for `queries[i]`.

Return an array containing the result for the given `queries`.

**Example 1:**

```
Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1].
```

**Example 2:**

```
Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]
```

**Example 3:**

```
Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]
```

**Constraints:**

* `1 <= m <= 10^3`
* `1 <= queries.length <= m`
* `1 <= queries[i] <= m`

---

## Solution & Editorial
# Intuition
The problem requires us to maintain a dynamic permutation $P$ of size $m$ and perform two operations for each query: finding the index of an element and moving that element to the front. Since $m$ is relatively small ($m \le 1000$), a direct simulation using a vector is efficient enough to handle the constraints.

# Approach
1. Initialize a vector `permutes` with values from $1$ to $m$.
2. For each query in `queries`, perform a recursive search (or iterative loop) to find the current index of the target value.
3. Once found, record the index in the `ans` vector.
4. Construct a new permutation by placing the target value at the front and appending the remaining elements of the previous permutation in their original relative order.
5. Repeat until all queries are processed.

### Visual Trace (Example 1: queries=[3,1,2,1], m=5)
| Step | Query | Current P | Index Found | New P |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | [1, 2, 3, 4, 5] | 2 | [3, 1, 2, 4, 5] |
| 1 | 1 | [3, 1, 2, 4, 5] | 1 | [1, 3, 2, 4, 5] |
| 2 | 2 | [1, 3, 2, 4, 5] | 2 | [2, 1, 3, 4, 5] |
| 3 | 1 | [2, 1, 3, 4, 5] | 1 | [1, 2, 3, 4, 5] |

# Complexity
- Time complexity: $$O(N \cdot M)$$, where $N$ is the number of queries and $M$ is the size of the permutation. For each of the $N$ queries, we iterate through the permutation of size $M$ to find the element and rebuild the vector.
- Space complexity: $$O(M)$$, as we store the permutation of size $M$ and the result vector of size $N$.

# Code
```cpp
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> permutes(m);
        vector<int> ans;
        for(int i = 0;i<m;i++){
            permutes[i] = i+1;
        }
        permute(permutes,queries,0,ans);
        return ans;

    }
    void permute(vector<int>& cur,vector<int>& queries,int index,vector<int>& ans){
        if(index == queries.size()) return;
        vector<int> next;
        next.push_back(queries[index]);
        for(int i = 0;i<cur.size();i++){
            if(cur[i] == queries[index]){
                ans.push_back(i);
                continue;
            } 
            next.push_back(cur[i]);
        }
        permute(next,queries,index+1,ans);

        return;
    }

};
```
