# [3691. Maximum Total Subarray Value II](https://leetcode.com/problems/maximum-total-subarray-value-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `greedy`, `segment-tree`, `heap-priority-queue`

---

## Problem Description
You are given an integer array `nums` of length `n` and an integer `k`.

You must select **exactly** `k` **distinct** subarrays `nums[l..r]` of `nums`. Subarrays may overlap, but the exact same subarray (same `l` and `r`) **cannot** be chosen more than once.

The **value** of a subarray `nums[l..r]` is defined as: `max(nums[l..r]) - min(nums[l..r])`.

The **total value** is the sum of the **values** of all chosen subarrays.

Return the **maximum** possible total value you can achieve.

**Example 1:**

**Input:** nums = [1,3,2], k = 2

**Output:** 4

**Explanation:**

One optimal approach is:

* Choose `nums[0..1] = [1, 3]`. The maximum is 3 and the minimum is 1, giving a value of `3 - 1 = 2`.
* Choose `nums[0..2] = [1, 3, 2]`. The maximum is still 3 and the minimum is still 1, so the value is also `3 - 1 = 2`.

Adding these gives `2 + 2 = 4`.

**Example 2:**

**Input:** nums = [4,2,5,1], k = 3

**Output:** 12

**Explanation:**

One optimal approach is:

* Choose `nums[0..3] = [4, 2, 5, 1]`. The maximum is 5 and the minimum is 1, giving a value of `5 - 1 = 4`.
* Choose `nums[1..3] = [2, 5, 1]`. The maximum is 5 and the minimum is 1, so the value is also `4`.
* Choose `nums[2..3] = [5, 1]`. The maximum is 5 and the minimum is 1, so the value is again `4`.

Adding these gives `4 + 4 + 4 = 12`.

**Constraints:**

* `1 <= n == nums.length <= 5 * 10​​​​​​​4`
* `0 <= nums[i] <= 109`
* `1 <= k <= min(105, n * (n + 1) / 2)`

---

## Solution & Editorial
# Intuition
The problem asks us to select $k$ distinct subarrays to maximize the sum of their values, where the value of a subarray is defined as `max - min`. Since we want to maximize the total sum, we should greedily pick the subarrays with the largest values. For a fixed starting index $i$, the value of a subarray `nums[i..j]` is non-increasing as $j$ decreases (because the range of values shrinks). This monotonicity allows us to use a priority queue to efficiently track the best available subarray starting at each index $i$.

# Approach
1. **Segment Tree**: Build a segment tree to perform range minimum and maximum queries in $O(\log N)$ time. This allows us to calculate the value of any subarray `nums[i..j]` efficiently.
2. **Priority Queue**: Initialize a max-priority queue with the largest possible subarray starting at each index $i$ (i.e., `nums[i..n-1]`).
3. **Greedy Selection**: In each of the $k$ steps:
   - Extract the subarray with the maximum value from the priority queue.
   - Add its value to the total `ans`.
   - Shrink the subarray by moving the end index $j$ to $j-1$ and push the new subarray `nums[i..j-1]` back into the priority queue if $i \le j-1$.

### Visual Trace (Example 1: nums=[1,3,2], k=2)
| Step | PQ State (i, j, val) | Pop | ans |
| :--- | :--- | :--- | :--- |
| Init | {(0,2,2), (1,2,1), (2,2,0)} | - | 0 |
| 1 | {(1,2,1), (2,2,0)} | (0,2,2) | 2 |
| 2 | {(0,1,2), (2,2,0)} | (1,2,1) | 3 |
| 3 | {(2,2,0), (0,0,0)} | (0,1,2) | 4 |

# Complexity
- Time complexity: $$O(N \log N + K \log N)$$. Building the segment tree takes $O(N)$. Initializing the priority queue takes $O(N \log N)$. Extracting and inserting into the priority queue $K$ times takes $O(K \log N)$.
- Space complexity: $$O(N)$$. The segment tree requires $O(N)$ space, and the priority queue stores at most $N$ elements.

# Code
```cpp
class Solution {

    struct PQNode{
        int i;
        int j;
        long long val;

        PQNode(int i, int j, long long val){
            this->i = i;
            this->j = j;
            this->val = val;
        }
    };

    struct Compare{
        bool operator()(PQNode &a, PQNode &b){
            return a.val < b.val;
        }
    };

    class SegmentTree{

        struct Node{
            int start;
            int end;
            int mn;
            int mx;

            Node* left;
            Node* right;

            Node(int start, int end){
                this->start = start;
                this->end = end;
                mn = INT_MAX;
                mx = INT_MIN;
                left = NULL;
                right = NULL;
            }
        };

        Node* root;

        Node* buildTree(vector<int>& nums, int start, int end){

            Node* node = new Node(start, end);

            if(start == end){
                node->mn = nums[start];
                node->mx = nums[start];
                return node;
            }

            int mid = (start + end) / 2;

            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);

            node->mn = min(node->left->mn, node->right->mn);
            node->mx = max(node->left->mx, node->right->mx);

            return node;
        }

        pair<int,int> query(Node* node, int start, int end){

            if(node == NULL){
                return {INT_MAX, INT_MIN};
            }

            if(start <= node->start && node->end <= end){
                return {node->mn, node->mx};
            }

            if(node->end < start || end < node->start){
                return {INT_MAX, INT_MIN};
            }

            pair<int,int> left = query(node->left, start, end);
            pair<int,int> right = query(node->right, start, end);

            int mn = min(left.first, right.first);
            int mx = max(left.second, right.second);

            return {mn, mx};
        }

    public:

        SegmentTree(vector<int>& nums){
            root = buildTree(nums, 0, nums.size() - 1);
        }

        pair<int,int> query(int start, int end){
            return query(root, start, end);
        }
    };

public:

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(nums);
        priority_queue<PQNode, vector<PQNode>, Compare> pq;

        for(int i = 0; i < n; i++){
            int j = n - 1;
            pair<int,int> res = st.query(i, j);
            long long val = (long long)res.second - res.first;
            pq.push(PQNode(i, j, val));
        }

        long long ans = 0;

        while(k-- > 0){
            PQNode peak = pq.top();
            pq.pop();

            ans += peak.val;

            int i = peak.i;
            int j = peak.j - 1;

            if(i <= j){
                pair<int,int> res = st.query(i, j);
                long long val = (long long)res.second - res.first;
                pq.push(PQNode(i, j, val));
            }
        }

        return ans;
    }
};
```
