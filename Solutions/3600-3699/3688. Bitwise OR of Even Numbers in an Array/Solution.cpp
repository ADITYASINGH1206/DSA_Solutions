class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(auto& num: nums){
            if(num%2 == 0) ans = ans | num;
        }
        return ans;
    }
};