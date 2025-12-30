class Solution {
public:
    bool isMagic(int row,int col,vector<vector<int>> &grid){
        vector<bool> vis(10,false);
        for(int i=0;i<3;i++){
            for(int j =0 ;j<3;j++){
                int num = grid[row+i][col+j];
                if(num < 1 || num > 9 || vis[num]) return false;
                vis[num] = true;
            }
        }
        if(grid[row+1][col+1]!= 5) return false;

        for(int i=0;i<3;i++){
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] !=  15) return false;
        }
        for(int i=0;i<3;i++){
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] !=  15) return false;
        }
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2]  != 15 )return false;
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col]  != 15 )return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isMagic(i,j,grid)) ans++;
            }
        }
        return ans;
    }
};