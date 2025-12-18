class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> prefix(n+1,0);
        long long sum=0;
        
        for(int i=0;i<n;i++){
            sum += 1LL * prices[i] * strategy[i];
            prefix[i+1] = sum;
        }
        long long ans=sum;
        long long curr =0;
        for(int i =k/2;i<k;i++){
            curr += prices[i];
        }
        
        for(int l=0;l+k<=n;l++){
            long long c = prefix[l+k] - prefix[l];
            ans = max(sum-c+curr,ans);
            if(l+k<n){
                curr += prices[l+k];
                curr-= prices[l+k/2];
            }
        }

        return ans;
    }
};