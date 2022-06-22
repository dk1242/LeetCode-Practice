class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int>st;
        int n=boxes.size();
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                st.insert(i);
            }
        }
        int sum=0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            sum=0;
            for(auto it:st){
                sum+=abs(i-it);
            }
            res[i]=sum;
        }
        return res;
    }
};