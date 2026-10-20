/**
 * Problem: Remove Sub-Folders from the Filesystem (1233)
 * Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (auto f : folder) {
            if (ans.empty()) {
                ans.push_back(f);
            } else {
                string& prev = ans.back();
                if(f.size()>prev.size() && f.substr(0,prev.size()) == prev && f.substr(prev.size(),1) == "/"){
                    continue;
                }else{
                    ans.push_back(f);
                }
            }
        }
        return ans;
    }
};
