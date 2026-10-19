class Solution {
public:
    void combination(int index, string &digits, string &path, vector<string> &ans, string mapping[]) {
        if (index == digits.length()) {
            ans.push_back(path);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            path.push_back(c); 
            combination(index + 1, digits, path, ans, mapping);
            path.pop_back();             
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string mapping[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string path = "";
        combination(0, digits, path, ans, mapping);
        return ans;
    }
};