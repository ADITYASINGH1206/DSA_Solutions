class Solution {
public:
    int minOperations(string s) {
        int t1 = 0;
        int t2 = 0;
        int n = s.size();
        int cur = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0' &&  i%2 == 0)t1++;
            else if(s[i] == '1' && i%2 != 0)t1++;
        }

        for (int i = 0; i < n; i++){
            if (s[i] == '0' &&  i%2 != 0)t2++;
            else if(s[i] == '1' && i%2 == 0)t2++;
        }
        int ans = min(t1,t2);
        return ans;
    }
};