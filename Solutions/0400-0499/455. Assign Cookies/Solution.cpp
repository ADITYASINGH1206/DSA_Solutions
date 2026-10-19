class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int children = 0 , cookie = 0;
        int m = g.size() , n =s.size();
        while(children<m && cookie<n){
            if(g[children]<=s[cookie]){
                ans++;
                children++;
                cookie++;
            }else{
                cookie++;
            }
        }
        return ans;
    }
};