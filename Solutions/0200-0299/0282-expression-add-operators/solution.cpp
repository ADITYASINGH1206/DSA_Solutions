/**
 * Problem: Expression Add Operators (282)
 * Link: https://leetcode.com/problems/expression-add-operators/
 * Difficulty: Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int i, string cur, string& num, vector<string>& ans, int target, long long total, long long prev){
        if(i == num.size()){
            if(total == target) ans.push_back(cur);
            return;
        }

        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') break;
            string currStr = num.substr(i, j - i + 1);
            long long currNum = stoll(currStr);
            if (i == 0) {
                backtrack(j + 1, currStr, num, ans, target, currNum, currNum);
            } else {
                backtrack(j + 1, cur + "+" + currStr, num, ans, target, total + currNum, currNum);
                backtrack(j + 1, cur + "-" + currStr, num, ans, target, total - currNum, -currNum);
                backtrack(j + 1, cur + "*" + currStr, num, ans, target, total - prev + (prev * currNum), prev * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        backtrack(0, "", num, ans, target, 0, 0);
        return ans;
    }
};
