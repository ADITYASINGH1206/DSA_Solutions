/**
 * Problem: Asteroid Collision (735)
 * Link: https://leetcode.com/problems/asteroid-collision/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();
        for(int i = 0;i<n;i++){
            if(asteroids[i] >0) st.push_back(asteroids[i]);
            else{
                while(!st.empty()&& st.back() > 0 && abs(asteroids[i]) > st.back()){
                    st.pop_back();
                }
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }
                else if(!st.empty() && st.back() > abs(asteroids[i])) continue;
                else if(st.empty()  || st.back() <0){
                    st.push_back(asteroids[i]);
                }
            }

        }
        return st;

    }
};
