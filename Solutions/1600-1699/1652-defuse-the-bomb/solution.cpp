/**
 * Problem: Defuse the Bomb (1652)
 * Link: https://leetcode.com/problems/defuse-the-bomb/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        int count = 0;
        if(k == 0) return ans;
        if(k>0){
            for(int i = 0;i<n;i++){
                int temp = 0;
                for(int j= 0;j<k;j++){
                    int idx = (i+1+j)%n;
                    temp += code[idx];
                }
                ans[i] = temp;
            }
        }
        else{
            int absk = abs(k);
            for(int i = 0;i<n;i++){
                int temp = 0;
                for(int j= 1;j<=absk;j++){
                    int idx =(i-j+n)%n;
                    temp += code[idx];
                }
                ans[i] = temp;
            }
        }




        return ans;
    }
};
