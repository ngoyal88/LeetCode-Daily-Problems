class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        for(int start = 0; start < k; start++){
            long long curr = LLONG_MIN/2;

            for(int j = start; j + k <= n; j += k){
                long long block = prefix[j+k] - prefix[j];
                curr = max(curr + block, block);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};