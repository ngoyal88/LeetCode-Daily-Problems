class Solution {
    const int MOD = 1e9+7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> sum(n+1,0);
        vector<long long> x(n+1,0);
        vector<long long> len(n+1,0);
        vector<long long> pow(n+1,0);

        pow[0] = 1;
        for(int i=1;i<=n;i++){
            pow[i] = (pow[i-1] * 10)%MOD;
        }

        for(int i=0;i<n;i++){
            sum[i+1] = sum[i];
            x[i+1] = x[i];
            len[i+1] = len[i];
            if(s[i] != '0'){
                int d = s[i] -'0';
                sum[i+1] += d;
                x[i+1] =( x[i] * 10 + d)%MOD;
                len[i+1]++;
            }
        }

        vector<int> ans;
        for(auto &it : queries){
            int l = it[0];
            int r = it[1];

            int right = len[r+1];
            int left = len[l];
            int length = right - left;

            if(length == 0){
                ans.push_back(0);
                continue;
            }
            long long a = (sum[r+1] - sum[l])%MOD;
            long long b = (x[r+1] - (x[l] * pow[length])%MOD + MOD)%MOD;
            long long res = (a*b)%MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};