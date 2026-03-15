class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        int thresh = 1000;

        while(thresh <= n){
            ans += n-thresh+1;
            if(n/1000 < thresh) break ;

            thresh *= 1000;
        }
        return ans;
    }
};