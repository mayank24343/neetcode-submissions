class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board){
        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()){
            if (board[x][y] == 'O'){
                board[x][y] = 'S';
                dfs(x+1, y, board);
                dfs(x,y+1, board);
                dfs(x-1, y, board);
                dfs(x, y-1, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++){
            if (board[i][0] == 'O'){
                dfs(i,0,board);
            }
            if (board[i][board[0].size()-1] == 'O'){
                dfs(i,board[0].size()-1, board);
            }
        }

        for (int i = 0; i < board[0].size(); i++){
            if (board[0][i] == 'O'){
                dfs(0,i, board);
            }
            if (board[board.size()-1][i] == 'O'){
                dfs(board.size()-1, i, board);
            }
        }

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
