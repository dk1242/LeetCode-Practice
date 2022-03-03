class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int r=row, c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')
                return false;
            r--;
        }
        r=row, c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')
                return false;
            r--, c--;
        }
        r=row, c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q')
                return false;
            r++,c--;
        }
        r=row, c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')
                return false;
            c--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&board, int col, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col]='Q';
                solve(ans, board, col+1, n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.');
        vector<string>board(n, s);
        solve(ans, board, 0, n);
        return ans;
    }
};