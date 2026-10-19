class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> decode;
        int ch = 0;
        for(int i = 0;i<key.size();i++){
            if(!decode[key[i]] && key[i] != ' '){
                decode[key[i]] = ('a'+ch++);
            }
        }
        string ans = "";
        for(char c:message){
            if(c!= ' ')ans += decode[c];
            else ans+= ' ';
        }
        return ans;
        
    }
};