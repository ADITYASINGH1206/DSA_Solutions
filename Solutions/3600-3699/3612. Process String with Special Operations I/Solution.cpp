class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto c:s){
            if(isalpha(c)) ans+= c;
            else if(c == '*' && ans.size() >0) ans.pop_back();
            else if(c == '#') ans += ans;
            else if(c == '%') reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};