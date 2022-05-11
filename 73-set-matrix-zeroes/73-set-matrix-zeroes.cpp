class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int>rows, cols;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    // matrix[0][j]=0, matrix[i][0]=0;
                    // matrix[i][j]=1;
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<m;j++){
                matrix[rows[i]][j]=0;
            }
        }
        for(int i=0;i<cols.size();i++){
            // if(matrix[0][i]==0)
            for(int j=0;j<n;j++){
                matrix[j][cols[i]]=0;
            }
        }
    }
};