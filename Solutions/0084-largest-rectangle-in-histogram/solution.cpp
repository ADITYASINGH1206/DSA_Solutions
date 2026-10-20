/**
 * Problem: Largest Rectangle in Histogram (84)
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> stk;

        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int width = right[i]- left[i] - 1;
            int area = width * heights[i];
            ans = max(ans,area);
        }

        return ans;
    }
};
