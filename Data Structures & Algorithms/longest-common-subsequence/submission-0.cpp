class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;
        int cand1, cand2;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 && j == 0) continue;
                if (text1[i] == text2[j]){
                    if (i > 0 && j > 0){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                
                cand1 = (i > 0) ? dp[i-1][j] : 0;
                cand2 = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = max({cand1, cand2, dp[i][j]});
                
            }
        }

        return dp[m-1][n-1];
    }
};
