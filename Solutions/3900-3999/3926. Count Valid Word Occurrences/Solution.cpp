class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (const string& chunk : chunks) {
            s += chunk;
        }
        
        unordered_map<string, int> mp;
        string cur = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                cur += c;
            } else if (c == '-') {
                if (i > 0 && i < n - 1 && 
                    s[i-1] >= 'a' && s[i-1] <= 'z' && 
                    s[i+1] >= 'a' && s[i+1] <= 'z') {
                    cur += c;
                } else {
                    if (!cur.empty()) {
                        mp[cur]++;
                        cur = "";
                    }
                }
            } else {
                if (!cur.empty()) {
                    mp[cur]++;
                    cur = "";
                }
            }
        }
        
        if (!cur.empty()) {
            mp[cur]++;
        }
        
        vector<int> ans;
        for (const string& q : queries) {
            ans.push_back(mp[q]);
        }
        
        return ans;
    }
};