class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        vector<int>res(n, 0);
        int c=0;
        for(int i=0;i<n;i++){
            if(ops[i]=="D"){
                res[c]=(res[c-1]*2);
                c++;
            }else if(ops[i]=="C"){
                c--;
            }else if(ops[i]=="+"){
                res[c]=(res[c-1]+res[c-2]);
                c++;
            }else{
                res[c]=(stoi(ops[i]));
                c++;
            }
        }
        int ans=0;
        for(int i=0;i<c;i++){
            ans+=res[i];
        }
        return ans;
    }
};