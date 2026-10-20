/**
 * Problem: Determine if Two Events Have Conflict (2446)
 * Link: https://leetcode.com/problems/determine-if-two-events-have-conflict/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(value(event1[1])<value(event2[0])||(value(event1[0])>value(event2[1]))){
            return false;
        }
        return true;
    }
    int value(string s){
        int hour = (((s[0]-'0')*10)+(s[1]-'0'))*60;
        int min = ((s[3]-'0')*10+(s[4]-'0'));
        return hour+min;
    }
};
