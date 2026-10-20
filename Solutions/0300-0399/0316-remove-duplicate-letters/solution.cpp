/**
 * Problem: Remove Duplicate Letters (316)
 * Link: https://leetcode.com/problems/remove-duplicate-letters/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        map<char,int>freq;
        for(int i = 0 ; i<n ;i++){
            freq[s[i]-'a'] = i;
        }
        vector<bool>isPresent(26,false);
        int i = 0;
        stack<char>st;
        while(i<n){
            if (isPresent[s[i] - 'a']){
                i++;
                continue;
            }
            while(!st.empty() && st.top() > s[i]  && freq[st.top() - 'a'] > i ){
                isPresent[st.top() - 'a'] = false;
                st.pop();
            }

            isPresent[s[i] - 'a'] = true;
            st.push(s[i]);
            
            i++;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
