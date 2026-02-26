class Solution {
public:
    int countArr(vector<int>& nums,int sum){
        int splits = 1;
        long long subSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(subSum + nums[i] <= sum){
                subSum += nums[i];
            }else{
                splits += 1;
                subSum = nums[i];
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = (low+high)/2;
            int splits = countArr(nums,mid);
            if(splits > k ){
                low = mid+1;
            }else{
                high = mid-1;
            }

        }
        return low;
    }
};