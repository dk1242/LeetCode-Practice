class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        vector<int>temp, temp1;
        temp.push_back(1);
        res.push_back(temp);
        for(int i=1;i<numRows;i++){
            if(i==1){
                temp.push_back(1);
                res.push_back(temp);
            }else{
                // temp1=temp;
                temp.push_back(1);
                for(int i=temp.size()-2;i>0;i--){
                    temp[i]=temp[i]+temp[i-1];
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};