class Solution {
public:
    int getLiveCount(vector<vector<int>>& temp, int i, int j){
        int c=0;
        if(i-1>=0 && temp[i-1][j]){
            c++;
        }
        if(i+1<temp.size() && temp[i+1][j]){
            c++;
        }
        if(j-1>=0 && temp[i][j-1]){
            c++;
        }
        if(j+1<temp[0].size() && temp[i][j+1]){
            c++;
        }
        if(i-1>=0 && j-1>=0 && temp[i-1][j-1])c++;
        if(i-1>=0 && j+1<temp[0].size() && temp[i-1][j+1])c++;
        if(i+1<temp.size() && j-1>=0 && temp[i+1][j-1])c++;
        if(i+1<temp.size() && j+1<temp[0].size() && temp[i+1][j+1])c++;
        return c;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size();
        int live=0;
        vector<vector<int>> temp=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                live=getLiveCount(temp, i, j);
                if(board[i][j]){
                    if(live<2 || live>3)
                        board[i][j]=0;
                }else {
                    if(live==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};