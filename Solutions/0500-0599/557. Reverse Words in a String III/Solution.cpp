class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        int n = s.size();
        string temp = "";
        for(char c:s){
            if(c != ' ') temp += c;
            else{
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += ' ';
                temp.clear();
            }
        }
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};