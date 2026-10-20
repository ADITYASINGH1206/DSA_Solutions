/**
 * Problem: Number of Even and Odd Bits (2595)
 * Link: https://leetcode.com/problems/number-of-even-and-odd-bits/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        bool turn =true;
        while(n){
            if(n%2){
                if(turn){
                    even++;
                }else{
                    odd++;
                }
            }
            n/=2;
            turn=!turn;
        }
        return {even,odd};
    }
};
