class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        long long x = 0;

        for(int i =0 ; i< n;i++){
            if(s[i] == '1')x++;
            else ans += x;
        }
        return ans;
    }
};