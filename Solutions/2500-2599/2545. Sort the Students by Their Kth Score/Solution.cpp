int r;
bool comp(vector<int>&a ,vector<int>&b){
    return (a[r]>b[r]);
}
class Solution {
public: 

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size();
        r=k;
        sort(score.begin(),score.end(),comp);
        return score;
    }
};