class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        // vector<int>rows, cols;
        int left=0, top=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0 && j==0)
                    left=1, top=1;
                    else if(i==0){
                        top=1;
                    }else if(j==0)
                        left=1;
                    matrix[0][j]=0, matrix[i][0]=0;
                    // matrix[i][j]=1;
                    // rows.push_back(i);
                    // cols.push_back(j);
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(top){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        
        if(left){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        // for(int i=0;i<rows.size();i++){
        //     for(int j=0;j<m;j++){
        //         matrix[rows[i]][j]=0;
        //     }
        // }
        // for(int i=0;i<cols.size();i++){
        //     // if(matrix[0][i]==0)
        //     for(int j=0;j<n;j++){
        //         matrix[j][cols[i]]=0;
        //     }
        // }
    }
};