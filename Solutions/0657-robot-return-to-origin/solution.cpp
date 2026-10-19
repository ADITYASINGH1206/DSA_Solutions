/**
 * Problem: Robot Return to Origin (657)
 * Link: https://leetcode.com/problems/robot-return-to-origin/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0 , y= 0;
        for(char i:moves){
            if(i=='U'){
                y--;
            }
            else if(i=='D'){
                y++;
            }else if(i=='L'){
                x--;
            }else if(i=='R'){
                x++;
            }
        }
        if(x==0&&y==0){
            return true;
        }
        return false;
    }
};
