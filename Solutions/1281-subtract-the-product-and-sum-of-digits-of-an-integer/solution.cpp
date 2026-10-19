/**
 * Problem: Subtract the Product and Sum of Digits of an Integer (1281)
 * Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1,sum=0;
        while(n>0){
            int digit = n%10;
            n/=10;
            product*=digit;
            sum+=digit;
        
        }
        return product-sum;
    }
};
