class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> s;
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> mp;
        for(int i = n2-1;i>=0;i--){
            while(!s.empty() && s.top() < nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                mp[nums2[i]] = s.top();
            }
            else{
                mp[nums2[i]] = -1;
            }
            s.push(nums2[i]);
        }
        for(int num:nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};