/**
 * Problem: Simplify Path (71)
 * Link: https://leetcode.com/problems/simplify-path/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string ans = "";
        stack<string> st; 
        string token = ""; 
        for(int i = 0 ; i <= n ; i++){
          if(i == path.size() || path[i] == '/'){
            if(token.empty() || token == "."){
            }
            else if(token == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(token);
            }
            token.clear();
          }
          else{
            token += path[i];
          }
        }
        
        vector<string> directories;
        while(!st.empty()){
            directories.push_back(st.top());
            st.pop();
        }
        reverse(directories.begin(), directories.end());

        for(auto str : directories){
            ans += "/";
            ans += str;
        }

        return ans.empty() ? "/" : ans;
    }
};
