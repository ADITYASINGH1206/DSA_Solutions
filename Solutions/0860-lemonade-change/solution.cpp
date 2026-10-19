/**
 * Problem: Lemonade Change (860)
 * Link: https://leetcode.com/problems/lemonade-change/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0,tens = 0;
        int n = bills.size();
        for(int i = 0 ;i < n;i++){
            if(bills[i] == 5){
                fives++;
            }else if(bills[i] == 10){
                if(fives){
                    fives--;
                    tens++;
                }else{
                    return false;
                }
            }else{
                if(fives && tens){
                    fives--;
                    tens--;
                }else if(fives >= 3){
                    fives -= 3;
                }else {
                    return false;
                }
            }
        }





        return true;
    }
};
