class Solution {
public:
    const int MOD = 1e9+7;
    long long fact(long long n) {
        long long res = 1;
        for (long long i = 2; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        return fact(n-1);
    }
};