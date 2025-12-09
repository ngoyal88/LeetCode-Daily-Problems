class Solution {
public:
    const int MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> freq,pair;
        for(int x:nums){
            if(x%2 ==0 && pair.count(x/2)){
                ans = (ans + pair[x/2])%MOD;
            }
            long long i = (long long)x*2;
            if (freq.count((int)i)) {
                pair[x] = (pair[x] + freq[(int)i]) % MOD;
            }
            freq[x]++;
        }
        return ans;
    }
};