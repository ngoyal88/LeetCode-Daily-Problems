class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long mini, maxi, ans;
        mini = min(need1, need2);
        maxi = max(need1, need2);
        ans = need1 * cost1 + need2 * cost2;
        ans = min(ans, mini * costBoth + (need1 - mini) * cost1 + (need2 - mini) * cost2);
        ans = min(ans,  maxi * costBoth);
        return ans;
    }
};