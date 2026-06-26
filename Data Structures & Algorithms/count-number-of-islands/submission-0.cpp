class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid, int m, int n){
        grid[x][y] = '0';
        vector<vector<int>> offsets = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& o : offsets){
            int new_x = x+o[0];
            int new_y = y+o[1];

            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y]=='1'){
                dfs(new_x,new_y, grid, m, n);
            }
        }            
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    dfs(i,j,grid, m, n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
