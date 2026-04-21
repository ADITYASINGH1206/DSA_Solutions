class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans = 0;
        int maxi = 0;
        for(auto [key,value] : mp){
            if(value > maxi){
                ans = value;
                maxi = value;
            }
            else if(value == maxi){
                ans += value;
            }
        }
        return ans;
    }
};