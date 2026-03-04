class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> ch(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            ch[s[i]-'a'] = i;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(ch[t[i]-'a']-i);
        }
        return ans;
    }
};