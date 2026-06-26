class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        int in_this_level = 0, in_next_level;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    q.emplace(i,j);
                    in_this_level++;
                }
            }
        }


        int dist = 0;
        vector<pair<int,int>> offsets = {{0,1},{1,0},{0,-1},{-1,0}};
        int x, y, newx, newy;


        while (!q.empty()){
            in_next_level = 0;
            dist++;

            for (int i = 0; i < in_this_level; i++){
                auto t = q.front(); 
                q.pop();

                x = t.first;
                y = t.second;

                for (auto& o : offsets){
                    newx = x+o.first;
                    newy = y+o.second;

                    if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == INT_MAX){
                        cout << newx << " "<<newy << endl;
                        grid[newx][newy] = dist;
                        q.emplace(newx,newy);
                        in_next_level++;
                    }
                }
            }

            in_this_level = in_next_level;
            
        }

    }
};
