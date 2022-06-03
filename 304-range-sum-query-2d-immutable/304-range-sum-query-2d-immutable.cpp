class NumMatrix {
public:
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        sum.resize(n+1, vector<int>(m+1, 0));
        sum[1][1]=matrix[0][0];
        for(int i=1;i<m;i++){
            sum[1][i+1]=sum[1][i]+matrix[0][i];
        }
        for(int i=1;i<n;i++){
            sum[i+1][1]=sum[i][1]+matrix[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]+matrix[i][j]-sum[i][j];
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout<<sum[row1][col1]<<" "<<sum[row2][col2]<<"@";
        int extra=sum[row1][col2+1]+sum[row2+1][col1];
        return sum[row2+1][col2+1]+sum[row1][col1]-extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */