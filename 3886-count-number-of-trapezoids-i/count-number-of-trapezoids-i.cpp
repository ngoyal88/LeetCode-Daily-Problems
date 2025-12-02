class Solution {
public:
    const int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> mp;
        for(auto it : points){
            mp[it[1]]++;
        }
        vector<long long> pairs;
        for(auto [y,count] : mp){
            if(count > 1){
                long long  it = 1LL *count*(count-1)/2LL;
                pairs.push_back(it);
            }
        }
        long long total = 0;
        for(auto &it : pairs) total += it;
        
        long long ans =0;
        for(auto &it : pairs){
            total = total - it;
            ans = (ans + it * total % MOD)%MOD;
        }
        return (int)ans;
    }
};