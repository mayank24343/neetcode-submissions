class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size(), in_this_level = 0, in_next_level = 0;
        int ripe = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.emplace(i,j);
                    in_this_level++;
                }
                else if (grid[i][j] == 1){
                    ripe++;
                }
            }
        }

        if (ripe == 0) return 0;
        int level = 0, x,y,newx,newy;
        vector<vector<int>> offsets = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()){
            in_next_level = 0;
            level++;
            for (int i = 0; i < in_this_level; i++){
                auto top = q.front(); q.pop();

                x = top.first;
                y = top.second;

                for (auto& o : offsets){
                    newx = x+o[0];
                    newy = y+o[1];

                    if (newx >= 0 && newy>= 0 && newx< m && newy< n){
                        if (grid[newx][newy] == 1){
                            grid[newx][newy] = 2;
                            ripe--;
                            q.emplace(newx,newy);
                            in_next_level++;
                        }
                    }
                }
            }

            in_this_level = in_next_level;
        }

        

        if (ripe > 0) return -1;
        return level-1;

    }
};
