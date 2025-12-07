class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int &it:nums)sum+=it;
        long long cur=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            cur += nums[i];
            if(abs(cur+cur-sum)%2==0)ans++;
        }
        return ans;
    }
};