/**
 * Problem: Find Most Frequent Vowel and Consonant (3541)
 * Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }

        int max_vowels=0;
        int max_conso=0;

        for(auto p:mp){
           char c = p.first;
           int frequency = p.second;

           if(c =='a' || c =='e' || c =='i' || c=='o' || c=='u'){
            max_vowels=max(max_vowels , frequency);
           }
           else{
            max_conso=max(max_conso , frequency);
           }
        }
        return max_vowels + max_conso;
        
    }
};
