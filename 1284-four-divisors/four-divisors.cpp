class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 2;
            int sum = nums[i] + 1;

            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    int d = nums[i] / j;
                    if (j == d) {
                        cnt += 1;
                        sum += j;
                    } else {
                        cnt += 2;
                        sum += j + d;
                    }
                }
                if (cnt > 4) break;
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};