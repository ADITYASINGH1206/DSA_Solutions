/**
 * Problem: Fruits Into Baskets II (3477)
 * Link: https://leetcode.com/problems/fruits-into-baskets-ii/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n=fruits.size();
        int ans=n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (fruits[i]<=baskets[j]){
                    ans--;
                    baskets[j]=0;
                    break;
                }
            }
        }
        return ans;
    }
};
