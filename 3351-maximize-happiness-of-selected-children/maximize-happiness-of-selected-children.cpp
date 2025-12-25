class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        for (int i = 0; i < k; i++) {
            int curr = happiness[i] - i;
            if (curr <= 0) break;
            ans += curr;
        }
        return ans;
    }
};