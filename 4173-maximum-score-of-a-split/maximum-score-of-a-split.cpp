class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        long long score =LLONG_MIN,pref = 0;
        vector<long long> suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = min(suffix[i+1],(long long)nums[i]);
        }
        for(int i=0;i<n-1;i++){
            pref += nums[i];
            long long curr = pref-suffix[i+1];
            score = max(curr,score);
        }
        return score;
    }
};