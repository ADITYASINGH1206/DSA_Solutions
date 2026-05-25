class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        for(int i =0 ;i<k;i++){
            lsum += cardPoints[i];
        }
        ans = lsum;
        int r = n-1;
        for(int i = k-1;i>-1;i--){
            rsum += cardPoints[r];
            lsum -= cardPoints[i];
            ans = max(ans,lsum+rsum);
            r--;
        }
        return ans;

    }
};