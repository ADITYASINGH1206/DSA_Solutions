/**
 * Problem: Count Vowel Strings in Ranges (2559)
 * Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n,0);
        vector<int>ans;
        int count=0;
        for(int i =0;i<n;i++){
            string&s = words[i];
            if(isVowel(s.front())&&isVowel(s.back())){
                count++;
            }
            prefix[i]=count;
        }
        for(auto&query:queries){
            int l = query[0];
            int r = query[1];
            if(l>0){
                ans.push_back(prefix[r]-prefix[l-1]);
            }else{
                ans.push_back(prefix[r]);
            }
        }
        return ans;
    }
};
