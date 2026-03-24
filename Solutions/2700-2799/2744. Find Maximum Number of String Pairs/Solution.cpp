class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;
        for(auto word : words){
            if(mp.find(word) != mp.end()) ans++;
            reverse(word.begin(),word.end());
            mp[word]++;
        }
        return ans;
    }
};