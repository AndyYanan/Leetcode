class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        dfs(res, board, 0, n);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& board, int row, int n){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int col = 0; col < n; ++col){
            if(isValid(borad, row, col, n)){
                board[row][col] = 'Q';
                dfs(res, board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = col+1, j = row-1; i < n && j >= 0; i++, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = col-1, j = row-1; i < n && j < n; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};