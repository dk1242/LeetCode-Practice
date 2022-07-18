class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res=0, n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int c=i;c<m;c++){
                for(int j=0;j<n;j++){
                    int sum=0;
                    for(int r=j;r<n;r++){
                        sum+=matrix[r][c]-(i>0 ? matrix[r][i-1]:0);
                        if(sum==target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};