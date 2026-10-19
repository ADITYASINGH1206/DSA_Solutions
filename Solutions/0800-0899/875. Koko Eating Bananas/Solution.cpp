class Solution {
public:
    int helper(vector<int>& piles){
        int mx = INT_MIN;
        int n = piles.size();
        for(int i =0;i<n;i++){
            mx = max(mx,piles[i]);
        }
        return mx;
    }
    long long TotalHours(vector<int>& piles,int speed){
        long long hrs = 0;
        for(int x: piles){
            hrs += (x+speed-1LL)/speed;

        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = helper(piles);
        while(low<= high){
            int mid = (low+high)/2;
            long long hrs = TotalHours(piles,mid);
            if(hrs <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};