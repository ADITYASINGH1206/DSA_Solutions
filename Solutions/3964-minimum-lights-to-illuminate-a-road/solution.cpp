/**
 * Problem: Minimum Lights to Illuminate a Road (3964)
 * Link: https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (lights[i] > 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                
                diff[left]++;
                diff[right + 1]--;
            }
        }
        vector<bool> dark(n, false);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            if (cur == 0) {
                dark[i] = true;
            }
        }
        int ans = 0;
        int i = 0;
        
        while (i < n) {
            if (dark[i]) {
                ans++;
                i += 3; 
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
