class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        long long ans=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string key;
            key.reserve(m - 1);
            for(int j=0;j<m-1;j++){  
                int diff = (words[i][j+1] - words[i][j] + 26)%26;
                key.push_back(char(diff));
            }
            if(mp.count(key))ans+= mp[key];
            mp[key]++;
        }
        return ans;
    }
};