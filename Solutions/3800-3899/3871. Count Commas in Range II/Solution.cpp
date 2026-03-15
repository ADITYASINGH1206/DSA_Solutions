class Solution {
public:
    long long countCommas(long long n) {
    long long ans = 0;
    long long thresh = 1000;

    while (thresh <= n) {
        ans += (n - thresh + 1);
        
        if (n / 1000 < thresh) {
            break;
        }
        thresh *= 1000;
    }

    return ans;
    }
};