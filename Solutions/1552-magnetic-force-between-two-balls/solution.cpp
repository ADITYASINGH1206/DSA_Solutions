/**
 * Problem: Magnetic Force Between Two Balls (1552)
 * Link: https://leetcode.com/problems/magnetic-force-between-two-balls/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        while (l < r) {
            int mid = r - (r - l) / 2;
            if (count(position, mid) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
};
