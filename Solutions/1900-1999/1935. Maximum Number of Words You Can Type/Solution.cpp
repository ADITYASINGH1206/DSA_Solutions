class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {false};
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int ans = 0;
        bool canType = true;

        for (char c : text) {
            if (c == ' ') {
                if (canType) {
                    ans++;
                }
                canType = true;
            } else if (broken[c - 'a']) {
                canType = false;
            }
        }
        
        if (canType) {
            ans++;
        }

        return ans;
    }
};