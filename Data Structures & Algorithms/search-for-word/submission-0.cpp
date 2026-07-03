class Solution {
public:

    bool dfs(int i, int j, const vector<vector<char>>& board, const string& word, int ind, vector<vector<int>>& visited){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        bool val = false;
        if (word[ind] == board[i][j] && visited[i][j] == 0) {
            //cout << i << " " << j << " " << word[ind] << " " << board[i][j] << endl;
            if (ind == word.size()-1) return true;
            visited[i][j] = 1;
            val = dfs(i+1, j, board, word, ind+1, visited) || dfs(i-1, j, board, word, ind+1, visited) || dfs(i, j+1, board, word, ind+1, visited) || dfs(i, j-1, board, word, ind+1, visited);
            visited[i][j] = 0;
        }

        return val;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfs(i,j,board,word,0,visited)) return true;
            }
        }

        return false;
    }
};
