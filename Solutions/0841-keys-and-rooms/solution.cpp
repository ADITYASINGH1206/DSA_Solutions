/**
 * Problem: Keys and Rooms (841)
 * Link: https://leetcode.com/problems/keys-and-rooms/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int key:rooms[room]){
                if(!vis[key]){
                    vis[key] = 1;
                    q.push(key);
                }
            }
        }

        for(int x:vis){
            if(!x){
                return false;
            }
        }
        return true;
    }
};
