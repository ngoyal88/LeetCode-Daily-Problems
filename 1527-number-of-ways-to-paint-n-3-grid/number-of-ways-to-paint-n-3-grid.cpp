class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int idx,int prev1,int prev2,int prev3,int n,vector<vector<vector<vector<int>>>> & dp){
        if(idx == n) return 1;
        int temp = dp[idx][prev1][prev2][prev3];
        if(temp != -1) return temp;
        int ans=0;
        for(int i=1;i<=3;i++){
            if(i==prev1) continue;
            for(int j=1;j<=3;j++){
                if(j == prev2 || i==j)continue;
                for(int k=1;k<=3;k++){
                    if(k==j || k==prev3)continue;
                    ans = (ans + solve(idx+1,i,j,k,n,dp))%MOD;
                }
            }
        }
        return dp[idx][prev1][prev2][prev3] = ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        return solve(0,0,0,0,n,dp);
    }
};