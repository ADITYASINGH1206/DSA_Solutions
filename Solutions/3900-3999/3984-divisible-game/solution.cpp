/**
 * Problem: Divisible Game (3984)
 * Link: https://leetcode.com/problems/divisible-game/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod_mul(int a, int b, int mod) {
        int res = 0;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res + a) % mod;
            }
            a = (a * 2) % mod;
            b /= 2;
        }
        return res;
    }

public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int min_val = nums[0];
        int max_val = nums[0];
        unordered_map<int, vector<int>> val_to_indices;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < min_val) min_val = nums[i];
            if (nums[i] > max_val) max_val = nums[i];
            val_to_indices[nums[i]].push_back(i);
        }
        
        int max_k = max_val > 2 ? max_val : 2;
        
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        int max_diff = -2000000000;
        int best_k = -1;
        
        for (int k = 2; k <= max_k; ++k) {
            vector<int> indices;
            
            for (int v = k; v <= max_val; v += k) {
                if (val_to_indices.count(v)) {
                    for (int idx : val_to_indices[v]) {
                        indices.push_back(idx);
                    }
                }
            }
            
            int diff = 0;
            if (indices.empty()) {
                diff = -min_val;
            } else {
                sort(indices.begin(), indices.end());
                
                int current_max = nums[indices[0]];
                int current_sum = nums[indices[0]];
                
                for (size_t j = 1; j < indices.size(); ++j) {
                    int prev = indices[j - 1];
                    int curr = indices[j];
                    
                    int gap = -(pref[curr] - pref[prev + 1]);
                    int val = nums[curr];
                    
                    current_sum = max(val, current_sum + gap + val);
                    if (current_sum > current_max) {
                        current_max = current_sum;
                    }
                }
                diff = current_max;
            }
            
            if (diff > max_diff) {
                max_diff = diff;
                best_k = k;
            } else if (diff == max_diff) {
                if (k < best_k) {
                    best_k = k;
                }
            }
        }
        
        return mod_mul(max_diff, best_k, 1000000007);
    }
};
