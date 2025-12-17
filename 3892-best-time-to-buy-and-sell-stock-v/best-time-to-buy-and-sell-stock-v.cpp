class Solution {
public:
    int n;
    vector<int> prices;
    vector<vector<vector<long long>>> dp;
    long long solve(int idx,int k,int state){
        if(idx==n || k==0){
            if(state == 0)return 0;
            return LLONG_MIN/4;
        }
        if(dp[idx][k][state] != -1)return dp[idx][k][state];
        long long ans=LLONG_MIN;

        if(state == 0){
            ans = max(ans,solve(idx+1,k,0));
            ans = max(ans,-prices[idx] + solve(idx+1,k,1));
            ans = max(ans,prices[idx] + solve(idx+1,k,2));
        }else if(state == 1){
            ans = max(ans,solve(idx+1,k,1));
            ans = max(ans,prices[idx] + solve(idx+1,k-1,0));
        }else if(state == 2){ 
            ans = max(ans,solve(idx+1,k,2));
            ans = max(ans,-prices[idx] + solve(idx+1,k-1,0));
        }
        return dp[idx][k][state] = ans;
    }
    long long maximumProfit(vector<int>& price, int k) {
        n = price.size();
        prices = price;
        dp.assign(n+1,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return solve(0,k,0);
    }
};