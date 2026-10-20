/**
 * Problem: Divisible and Non-divisible Sums Difference (2894)
 * Link: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int x= 0,y=0;
        for(int i  =1 ; i<=n;i++){
            if(i%m!=0){
                x+=i;
            }else{
                y+=i;
            }
        }
        return x-y;
    }
};
