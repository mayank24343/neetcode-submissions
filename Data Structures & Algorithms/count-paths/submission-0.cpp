class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;
        int dx[2] = {0,-1}, dy[2] = {-1,0}, cnt, nx, ny;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0) continue;
                cnt = 0;
                for (int k = 0; k < 2; k++){
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if (nx < 0 || ny < 0) continue;
                    cnt += dp[nx][ny];
                }

                
                dp[i][j] = cnt;

                
            }

        }

        return dp[m-1][n-1];
    }
};
