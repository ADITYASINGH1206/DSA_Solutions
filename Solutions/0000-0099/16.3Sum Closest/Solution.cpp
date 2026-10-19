class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(sum-target) < abs(ans-target)) ans = sum;
                if(sum>target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};