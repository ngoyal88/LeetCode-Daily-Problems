class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0;
        int mini = INT_MAX;
        for (auto &row : matrix) {
            for (int &it : row) {
                if (it < 0) cnt++;
                it = abs(it);
                sum += it;
                mini = min(it, mini);
            }
        }
        if (cnt % 2 == 0)
            return sum;
        return sum - 2 * mini;
    }
};