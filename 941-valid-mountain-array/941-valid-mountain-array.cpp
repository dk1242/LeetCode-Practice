class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag=0, flag1=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                if(flag1==1){
                    return false;
                }
                flag=1;
            }else if(arr[i]>arr[i+1]){
                if(flag==0)
                    return false;
                flag1=1;
            }else return false;
        }
        if(flag==1 && flag1==1)
        return true;
        else return false;
    }
};