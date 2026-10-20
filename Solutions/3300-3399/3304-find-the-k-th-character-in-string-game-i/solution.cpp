/**
 * Problem: Find the K-th Character in String Game I (3304)
 * Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while(ans.size() < k){
            string next = "";
            for(int i = 0;i<ans.size();i++){
                next += 'a' + ((ans[i]-'a' + 1)%26);
            }
            ans += next;
        }

        return ans[k-1];
    }
};
