/**
 * Problem: Convert Date to Binary (3280)
 * Link: https://leetcode.com/problems/convert-date-to-binary/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string binary(int num) {
        if (num == 0) return "0";
        
        string bin = "";
        while (num > 0) {
            bin += to_string(num % 2);
            num /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;   
    }

    string convertDateToBinary(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        return binary(y) + "-" + binary(m) + "-" + binary(d);
    }
};
