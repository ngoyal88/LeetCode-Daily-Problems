class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> solved(n-1,false);
        int left = n-1;
        int ans=0;
        for(int j=0;j<m && left>0;j++){
            bool flag = false;
            for(int i=0;i<n-1;i++){
                if(!solved[i] && strs[i][j] > strs[i+1][j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(!solved[i] && strs[i][j] < strs[i+1][j]){
                    solved[i] = true;
                    left--;
                }
            }
        }
        return ans;
    }
};