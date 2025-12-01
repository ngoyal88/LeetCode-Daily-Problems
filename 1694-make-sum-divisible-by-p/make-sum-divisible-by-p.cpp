class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for(auto &it : nums) total += it;
        
        int need = total%p;
        if(need == 0)return 0;
        
        long long prefix=0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = n;

        for(int i=0;i<n;i++){
            prefix = (prefix + nums[i])%p;

            int want = (prefix - need + p)%p;

            if(mp.count(want)){
                ans = min(ans, i - mp[want]);
            }
            mp[prefix] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};