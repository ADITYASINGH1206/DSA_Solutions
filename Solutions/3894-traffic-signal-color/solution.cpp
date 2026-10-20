/**
 * Problem: Traffic Signal Color (3894)
 * Link: https://leetcode.com/problems/traffic-signal-color/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) {
            return "Green";
        }
        if (timer == 30) {
            return "Orange";
        }
        if (timer > 30 && timer <= 90) {
            return "Red";
        }
        return "Invalid";
    }
};
