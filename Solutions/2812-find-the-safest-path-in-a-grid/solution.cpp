/**
 * Problem: Find the Safest Path in a Grid (2812)
 * Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1){
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nr = r + dx[d];
                int nc = c + dy[d];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(vis[nr][nc]) continue;

                dist[nr][nc] = dist[r][c] + 1;
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        priority_queue<pair<int, pair<int,int>>> store;
        vector<vector<bool>> vis2(n, vector<bool>(n, false));

        store.push({dist[0][0], {0, 0}});

        while(!store.empty()){
            auto pr = store.top();
            store.pop();

            int safeE = pr.first;
            int r = pr.second.first;
            int c = pr.second.second;

            if(vis2[r][c]) continue;
            vis2[r][c] = true;
            if(r == n - 1 && c == n - 1) return safeE;

            for(int d = 0; d < 4; d++){
                int nr = r + dx[d];
                int nc = c + dy[d];

                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(vis2[nr][nc]) continue;

                int newSafe = min(safeE, dist[nr][nc]);
                store.push({newSafe, {nr, nc}});
            }
        }

        return 0;
    }
};
