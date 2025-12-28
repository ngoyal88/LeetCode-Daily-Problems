class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        long long score =LLONG_MIN;
        vector<long long> prefix(n),suffix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = min(suffix[i+1],(long long)nums[i]);
        }
        for(int i=0;i<n-1;i++){
            long long curr = prefix[i]-suffix[i+1];
            score = max(curr,score);
        }
        return score;
    }
};