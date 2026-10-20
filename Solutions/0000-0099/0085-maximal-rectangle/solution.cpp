/**
 * Problem: Maximal Rectangle (85)
 * Link: https://leetcode.com/problems/maximal-rectangle/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRectangle(vector<int>& heights){
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
        for(int i =0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i]* width;
            ans = max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n,0);
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1')heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans,maximumRectangle(heights));
        }

        return ans;
        
    }
};
