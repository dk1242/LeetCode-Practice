class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n, vector<int>(n, 0));
        int rowBeg=0, rowEnd=n-1, c=1,colBeg=0, colEnd=n-1;
        while(rowBeg<=rowEnd && colBeg<=colEnd){
            for(int i=colBeg;i<=colEnd;i++){
                res[rowBeg][i]=c++;
            }
            rowBeg++;
            for(int i=rowBeg;i<=rowEnd;i++){
                res[i][colEnd]=c++;
            }
            colEnd--;
            for(int i=colEnd;i>=colBeg;i--){
                res[rowEnd][i]=c++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowBeg;i--){
                res[i][colBeg]=c++;
            }
            colBeg++;;
        }
        return res;
    }
};