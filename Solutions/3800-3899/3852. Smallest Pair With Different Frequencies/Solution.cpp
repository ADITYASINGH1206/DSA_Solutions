class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        auto it = freq.begin();
        int x = it->first;
        int x_freq = it->second;
        it++;
        for (; it != freq.end(); ++it) {
            if (it->second != x_freq) {
                return {x, it->first};
            }
        }
        
        return {-1, -1};
    }
};