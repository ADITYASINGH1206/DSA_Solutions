class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int i = n-1;
        while(num[i] == '0'){
            num.pop_back();
            i--;

        }
        return num;
    }
};