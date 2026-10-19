class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp_row;
        int ans = 0;
        int n = grid.size();

        for (const auto& row : grid) {
            mp_row[row]++;
        }

        for (int i = 0; i < n;i++) {
            vector<int> col(n);
            for (int j = 0; j < n;j++) {
                col[j] = grid[j][i];
            }
            ans += mp_row[col];
        }

        return ans;
    }
};