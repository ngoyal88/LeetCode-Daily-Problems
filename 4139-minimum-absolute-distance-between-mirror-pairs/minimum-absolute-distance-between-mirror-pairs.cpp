class Solution {
public:
    long long rev(long long n){
        long long ans=0;
        while(n > 0){
            ans = ans*10 + (n%10);
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans= INT_MAX;

        unordered_map<long long,int> mp;

        for(int j=0;j<n;j++){
            int r = rev(nums[j]);
            if(mp.count(nums[j])){
                ans = min(ans,j-mp[nums[j]]);
            }

            mp[r] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};