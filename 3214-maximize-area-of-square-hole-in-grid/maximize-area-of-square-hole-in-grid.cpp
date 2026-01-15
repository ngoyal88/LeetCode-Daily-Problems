class Solution {
public:
    int solve(vector<int> &vec){
        int len=1,curr=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i-1] == vec[i]-1) curr++;
            else curr = 1;
            len = max(curr, len);
        }
        return len+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int s = min(solve(hBars),solve(vBars));
        return s*s;
    }
};