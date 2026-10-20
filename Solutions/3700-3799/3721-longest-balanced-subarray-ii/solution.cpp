/**
 * Problem: Longest Balanced Subarray II (3721)
 * Link: https://leetcode.com/problems/longest-balanced-subarray-ii/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int min_val;
        int max_val;
        int lazy;
    };

    vector<Node> tree;
    int n;


    void push(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            if (start != end) {
                tree[2 * node].min_val += tree[node].lazy;
                tree[2 * node].max_val += tree[node].lazy;
                tree[2 * node].lazy += tree[node].lazy;

                tree[2 * node + 1].min_val += tree[node].lazy;
                tree[2 * node + 1].max_val += tree[node].lazy;
                tree[2 * node + 1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node].min_val += val;
            tree[node].max_val += val;
            tree[node].lazy += val;
            return;
        }

        push(node, start, end);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }

    int findFirstZero(int node, int start, int end, int limit) {
        if (start > limit) return -1;
        
        push(node, start, end);


        if (tree[node].min_val > 0 || tree[node].max_val < 0) return -1;


        if (start == end) {
            return (tree[node].min_val == 0) ? start : -1;
        }

        int mid = (start + end) / 2;
        
        int res = findFirstZero(2 * node, start, mid, limit);
        if (res != -1) return res;

        return findFirstZero(2 * node + 1, mid + 1, end, limit);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, {0, 0, 0});
        map<int, int> last_pos;
        int max_len = 0;
        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = -1;
            
            if (last_pos.count(val)) {
                prev = last_pos[val];
            }

            int change = (val % 2 == 0) ? 1 : -1;
            update(1, 0, n - 1, prev + 1, j, change);

            int i = findFirstZero(1, 0, n - 1, j);

            if (i != -1) {
                max_len = max(max_len, j - i + 1);
            }

            last_pos[val] = j;
        }

        return max_len;
    }
};
