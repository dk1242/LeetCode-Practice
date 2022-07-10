class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j])
                    ans++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j])
                matrix[i][j]+=min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
                if(matrix[i][j]>1)
                    ans+=matrix[i][j]-1;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<(matrix[i][j])<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return ans;
    }
};