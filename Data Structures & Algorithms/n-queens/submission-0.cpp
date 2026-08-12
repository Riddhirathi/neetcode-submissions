class Solution {
public:
    vector<vector<string>> ans;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    void dfs (vector<string>& board, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            int d1 = row-c+n-1;
            int d2 = row+c;
            if(col[c] || diag1[d1] || diag2[d2]) continue;
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            dfs(board, row+1, n);
            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.resize(n, false);
        diag1.resize(2*n-1, false);
        diag2.resize(2*n-1, false);
        dfs(board, 0, n);
        return ans;
    }
};
