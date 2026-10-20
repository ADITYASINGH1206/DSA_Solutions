/**
 * Problem: Maximize the Distance Between Points on a Square (3464)
 * Link: https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        if (k == 2) {
            long long max_sum = -4e18, min_sum = 4e18;
            long long max_diff = -4e18, min_diff = 4e18;
            for (const auto& pt : points) {
                long long sum = (long long)pt[0] + pt[1];
                long long diff = (long long)pt[0] - pt[1];
                max_sum = max(max_sum, sum);
                min_sum = min(min_sum, sum);
                max_diff = max(max_diff, diff);
                min_diff = min(min_diff, diff);
            }
            return max(max_sum - min_sum, max_diff - min_diff);
        }

        vector<long long> p;
        for (const auto& pt : points) {
            long long x = pt[0], y = pt[1];
            if (y == 0) p.push_back(x);
            else if (x == side) p.push_back(side + y);
            else if (y == side) p.push_back(3LL * side - x);
            else p.push_back(4LL * side - y);
        }

        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        int n = p.size();
        
        if (n < k) return 0;

        int LOG = 0;
        while ((1 << LOG) <= k) LOG++;
        vector<long long> p2(2 * n);
        for (int i = 0; i < n; ++i) {
            p2[i] = p[i];
            p2[i + n] = p[i] + 4LL * side;
        }
        auto check = [&](long long d) {
            vector<int> nxt(2 * n + 1, 2 * n);
            int j = 0;
            
            for (int i = 0; i < 2 * n; ++i) {
                while (j < 2 * n && p2[j] - p2[i] < d) {
                    j++;
                }
                nxt[i] = j;
            }

            vector<vector<int>> up(LOG, vector<int>(2 * n + 1, 2 * n));
            for (int i = 0; i <= 2 * n; ++i) up[0][i] = nxt[i];

            for (int step = 1; step < LOG; ++step) {
                for (int i = 0; i <= 2 * n; ++i) {
                    up[step][i] = up[step - 1][up[step - 1][i]];
                }
            }

            for (int i = 0; i < n; ++i) {
                int curr = i; 
                for (int step = 0; step < LOG; ++step) {
                    if ((k >> step) & 1) {
                        curr = up[step][curr];
                    }
                }
                if (curr <= i + n) return true;
            }
            return false;
        };

        long long low = 0, high = 2e9; 
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return ans;
    }
};
