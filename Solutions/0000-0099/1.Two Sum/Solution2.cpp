// Brute Force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0;; ++i) {
            for (int j = i + 1;; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
    }
};