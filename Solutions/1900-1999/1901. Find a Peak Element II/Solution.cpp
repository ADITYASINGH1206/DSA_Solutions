class Solution {
public:
    int helper(vector<vector<int>>& mat,int n,int m,int col){
        int maxi = INT_MIN;
        int index = -1;
        for(int i =0;i<n;i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 ;
        int high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int mx = helper(mat,n,m,mid);
            int l = mid -1 > 0 ? mat[mx][mid-1] : -1;
            int r = mid+ 1 < m ? mat[mx][mid+1] : -1;
            if(mat[mx][mid] > l && mat[mx][mid] > r){
                return {mx,mid};
            }else if(mat[mx][mid] < l){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};