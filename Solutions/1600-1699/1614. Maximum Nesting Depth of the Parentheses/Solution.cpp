class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int cur = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i] == '(') cur++;
            if(s[i] == ')') cur--;
            ans = max(cur,ans);
        }
        return ans;
    }
};