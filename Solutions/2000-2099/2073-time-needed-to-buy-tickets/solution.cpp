/**
 * Problem: Time Needed to Buy Tickets (2073)
 * Link: https://leetcode.com/problems/time-needed-to-buy-tickets/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int kth = tickets[k];
        int ans = 0;
        int size = tickets.size();
        while(tickets[k]){
            for(int i =0;i<tickets.size();i++){
                if(tickets[i] !=0){
                    ans++;
                    tickets[i] = tickets[i]-1;
                    if(i == k && tickets[i] == 0) return ans;
                }
            }
        }

        return ans;
    }
};
