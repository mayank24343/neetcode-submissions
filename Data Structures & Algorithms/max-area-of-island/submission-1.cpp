class Solution {
public:
    vector<vector<int>> offsets = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(const int x,const int y, vector<vector<int>>& grid,const int m,const int n){
        grid[x][y] = 0;
        int area = 1, newx, newy;
        
        for (auto& o : offsets){
            newx = x+o[0];
            newy = y+o[1];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n){
                if (grid[newx][newy] == 1){
                    area += dfs(newx, newy, grid, m, n);
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx_area = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    mx_area = max(mx_area, dfs(i,j,grid,m,n));
                } 
            }
        }

        return mx_area;
    }
};
