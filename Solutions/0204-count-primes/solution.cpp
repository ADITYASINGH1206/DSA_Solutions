/**
 * Problem: Count Primes (204)
 * Link: https://leetcode.com/problems/count-primes/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> primes(n+1,1);

        for(long long i = 2;i<=n;i++){
            if(primes[i] == 1){
                for(long long j = i*i ;j<=n;j+=i){
                    primes[j] = 0;
                }
            }
        }
        for(int i = 2;i<n;i++){
            if(primes[i]) ans++;
        }
        return ans;
    }
};
