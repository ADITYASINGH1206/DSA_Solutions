/**
 * Problem: Display Table of Food Orders in a Restaurant (1418)
 * Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> map;
        set<string> items;

        for (int i = 0, n = orders.size(); i < n; ++i) {
            int table = stoi(orders[i][1]);
            string food = orders[i][2];
            ++map[table][food];
            items.insert(food);
        }

        vector<vector<string>> ans;
        vector<string> header{"Table"};
        header.insert(header.end(), items.begin(), items.end());
        ans.push_back(header);

        for (auto [table, foodCount] : map) {
            vector<string> row{to_string(table)};
            for (string food : items) {
                if(foodCount.count(food)) row.push_back(to_string(foodCount.at(food)));
                else row.push_back("0");
            }
            ans.push_back(row);
        }
        return ans;
    }
};
