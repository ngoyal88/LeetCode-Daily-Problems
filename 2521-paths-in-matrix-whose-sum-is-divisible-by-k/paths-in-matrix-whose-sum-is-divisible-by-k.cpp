class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(K,0)));

        int rem = grid[0][0] %K;
        dp[0][0][rem] = 1;

        for(int i=1;i<n;i++){
            for(int r=0;r<K;r++)
                dp[i][0][(r + grid[i][0]) % K] += dp[i-1][0][r];
        }

        for(int j=1;j<m;j++){
            for(int r=0;r<K;r++)
                dp[0][j][(r + grid[0][j]) % K] += dp[0][j-1][r];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int k=0;k<K;k++){
                    int rem = (k+grid[i][j])%K;
                    dp[i][j][rem] = (dp[i][j][rem] + dp[i-1][j][k])%MOD;
                    dp[i][j][rem] = (dp[i][j][rem] + dp[i][j-1][k])%MOD;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};