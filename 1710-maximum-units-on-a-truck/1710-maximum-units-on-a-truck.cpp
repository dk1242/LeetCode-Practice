class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int n=box.size();
        sort(box.begin(), box.end(), comp);
        int ans=0;
        int i=0;
        while(truckSize>0 && i<n){
            if(truckSize-box[i][0]>0){
                ans+=box[i][0]*box[i][1];
                truckSize-=box[i][0];
                i++;
            }else{
                ans+=truckSize*box[i][1];
                truckSize=0;
            }
        }
        return ans;
    }
};