class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int r = n-1;
        int l = 0;
        while(l<r){
            r--;
            ans+=piles[r];
            r--;
            l++;
        }
        return ans;
    }
};