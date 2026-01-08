class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int sum = nums1[i] * nums2[j];
                int take = sum + max(0, dp[i+1][j+1]);
                int t1 = dp[i + 1][j];
                int t2 = dp[i][j + 1];
                dp[i][j] = max({t1, t2, take});
            }
        }

        return dp[0][0];
    }
};