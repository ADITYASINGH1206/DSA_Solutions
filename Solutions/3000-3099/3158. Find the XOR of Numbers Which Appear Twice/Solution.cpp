class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(51,0);
        for(int num:nums){
            freq[num]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i] == 2) ans = ans^i;
        }
        return ans;
    }
};