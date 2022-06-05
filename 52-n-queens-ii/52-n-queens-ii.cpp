class Solution {
public:
        bool isSafe(int r, int c, vector<string>&board, int n){
        int i=r, j=c;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            i--;
        }
        i=r, j=c;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            i--, j--;
        }
        i=r, j=c;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        i=r, j=c;
        while(i<n && j>=0){
            if(board[i][j]=='Q')
                return false;
            i++, j--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&board, int c, int n){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(isSafe(r, c, board, n)){
                board[r][c]='Q';
                solve(ans, board, c+1, n);
                board[r][c]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        solve(ans, board, 0, n);
        return ans.size();
    }
};