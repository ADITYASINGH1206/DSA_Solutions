/**
 * Problem: Number of Students Unable to Eat Lunch (1700)
 * Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        for (int student : students)
            counts[student]++;

        int ans = sandwiches.size();
        for (int s : sandwiches) {
            if (counts[s] == 0)
                break;
            if (ans == 0)
                break;
            counts[s]--;
            ans--;
        }

        return ans;
    }
};
