class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        int start = 0, mx_len = 1;

        for (int len = 2; len <= n; len++){
            for (int i = 0; i+len <= n; i++){
                dp[i][i+len-1] = (s[i] == s[i+len-1]) && ((len > 2) ? dp[i+1][i+len-2] : 1);
                if (dp[i][i+len-1] && len > mx_len){
                    mx_len = len;
                    start = i;
                }
            }
        }

        return s.substr(start, mx_len);

    }
};
