class Solution {
public:
    bool helper(vector<int>& bloomDay,int day,int m ,int k){
        int cnt =0;
        int Boquets = 0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                Boquets += (cnt/k);
                cnt = 0;
            }
        }
        Boquets += (cnt/k);
        return Boquets >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i =0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(helper(bloomDay,mid,m,k)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};