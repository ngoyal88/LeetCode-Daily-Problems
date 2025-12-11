class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
        unordered_map<int, int> min_col, max_col; 
        unordered_map<int, int> min_row, max_row;  

        for (auto& it : build) {
            int x = it[0], y = it[1];

            if (!min_col.count(x) || y < min_col[x]) min_col[x] = y;
            if (!max_col.count(x) || y > max_col[x]) max_col[x] = y;

            if (!min_row.count(y) || x < min_row[y]) min_row[y] = x;
            if (!max_row.count(y) || x > max_row[y]) max_row[y] = x;
        }

        int ans = 0;

        for (auto& it : build) {
            int x = it[0], y = it[1];

            bool l = min_col[x] < y;
            bool r = max_col[x] > y;
            bool u = min_row[y] < x;
            bool d = max_row[y] > x;

            if (l && r && u && d) {
                ans++;
            }
        }

        return ans;

    }
};