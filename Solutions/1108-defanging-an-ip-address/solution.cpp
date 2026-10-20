/**
 * Problem: Defanging an IP Address (1108)
 * Link: https://leetcode.com/problems/defanging-an-ip-address/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string output = "";
        for(int i=0 ; i<address.size() ; i++){
            if(address[i] == '.'){
                output += "[.]";
            }
            else{
                output+= address[i];
            }
        }
        return output;
    }
};
