class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int sum = (n*(n+1))/2;
        int l_sum = 0;
        int r_sum = 0;
        int total = (n*(n+1))/2;
        for(int i =1;i<=n;i++){
            l_sum += i;
            r_sum = (total-l_sum)+i;
            if(l_sum == r_sum) return i;
        }
        return -1;
    }
};