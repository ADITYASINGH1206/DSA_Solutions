/**
 * Problem: Finding 3-Digit Even Numbers (2094)
 * Link: https://leetcode.com/problems/finding-3-digit-even-numbers/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for(int d : digits){
            count[d]++; 
        }
        vector<int> ans;
        for(int i = 100; i <= 998; i += 2){
            int ones = i % 10;
            int tens = (i / 10) % 10;
            int hundreds = i / 100;
            count[ones]--;
            count[tens]--;
            count[hundreds]--;
            if(count[ones] >= 0 && count[tens] >= 0 && count[hundreds] >= 0){
                ans.push_back(i);
            }
            count[ones]++;
            count[tens]++;
            count[hundreds]++;
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     void recurse(int size, int num, vector<int>& digits, vector<bool>& visited, set<int>& uniqueAns) {
//         if(size == 3){
//             if(num % 2 == 0){
//                 uniqueAns.insert(num); 
//             }
//             return;
//         }

//         for(int i = 0; i < digits.size(); i++){
//             if(visited[i]) continue;
//             if(size == 0 && digits[i] == 0) continue;
//             visited[i] = true;
//             recurse(size + 1, num * 10 + digits[i], digits, visited, uniqueAns);
//             visited[i] = false;
//         }
//     }
    
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         set<int> uniqueAns;
//         vector<bool> visited(digits.size(), false);
//         recurse(0, 0, digits, visited, uniqueAns);
//         return vector<int>(uniqueAns.begin(), uniqueAns.end());
//     }
// };
