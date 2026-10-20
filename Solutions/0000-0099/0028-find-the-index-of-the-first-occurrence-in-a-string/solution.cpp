/**
 * Problem: Find the Index of the First Occurrence in a String (28)
 * Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        int i = 0;
        while(i <= n1 - n2){ 
            int j = 0;
            bool notFound = false;
            int start = i; 
            while(j < n2){
                if(haystack[i] == needle[j]){
                    j++;
                    i++;
                }
                else{
                    notFound = true;
                    break;
                }
            }
            
            if(notFound) {
                i = start + 1; 
            } else {
                return start; 
            }
        }

        return -1;
    }
};
