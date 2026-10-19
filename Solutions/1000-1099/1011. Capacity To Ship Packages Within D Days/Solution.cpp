class Solution {
public:
    bool daysReq(vector<int>& weights,int days,int cap){
        int dcnt = 0;
        int sum = weights[0];
        for(int i = 1;i<weights.size();i++){
            sum += weights[i];
            if(sum == cap){
                dcnt++;
                sum = 0 ;
            }else if(sum > cap){
                dcnt++;
                sum = weights[i];
            }
        }
        if(sum) dcnt++;
        
        return dcnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0 , high = 0;
        for(int i=0;i<weights.size();i++){
            low = max(low,weights[i]);
            high += weights[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(daysReq(weights,days,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return low;
        
    }
};