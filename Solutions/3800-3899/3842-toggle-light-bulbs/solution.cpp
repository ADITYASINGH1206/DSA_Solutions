/**
 * Problem: Toggle Light Bulbs (3842)
 * Link: https://leetcode.com/problems/toggle-light-bulbs/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool isOn[101] = {false}; 
        for (int b : bulbs) {
            isOn[b] = !isOn[b];
        }
        
        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
