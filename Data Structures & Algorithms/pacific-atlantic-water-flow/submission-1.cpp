class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights[0].size(), m = heights.size();
        vector<vector<int>> reachable(m, vector<int>(n,0));
        
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++){
            q.emplace(i,0);
            reachable[i][0] = 1;
        }
        for (int i = 1; i < n; i++){
            q.emplace(0,i);
            reachable[0][i] = 1;
        }
        int x, y, newx, newy;
        vector<pair<int,int>> offsets = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!q.empty()){
            auto top = q.front(); q.pop();
            x = top.first;
            y = top.second;
            for (auto& o : offsets){
                newx = x+o.first;
                newy = y+o.second;
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && heights[newx][newy] >= heights[x][y] && reachable[newx][newy] == 0){
                    reachable[newx][newy] = 1;
                    q.emplace(newx, newy);
                }
            }
        }

        for (int i = 0; i < m; i++){
            q.emplace(i,n-1);
            reachable[i][n-1]+=2;
        }
        for (int i = 0; i < n-1; i++){
            q.emplace(m-1,i);
            reachable[m-1][i]+=2;
        }

        while (!q.empty()){
            auto top = q.front(); q.pop();
            x = top.first;
            y = top.second;
            for (auto& o : offsets){
                newx = x+o.first;
                newy = y+o.second;
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && heights[newx][newy] >= heights[x][y] && reachable[newx][newy] < 2){
                    reachable[newx][newy] += 2;
                    q.emplace(newx, newy);
                }
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (reachable[i][j] == 3){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};
