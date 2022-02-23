class Solution {
public:
    void nextPermutation(vector<int>& a) {
       int n=a.size();
        int i=0,j,f=0;
        for(i=n-1;i>0;i--){
            // cout<<i;
            if(a[i-1]<a[i]){
                i--;
                f=1;
                break;
            }
        }
        cout<<i;
        if(i==0 && f==0){
            sort(a.begin(), a.end());
            return;
        }
        j=n;
        while(j--){
            if(a[i]<a[j]){
                cout<<j;
                swap(a[i], a[j]);
                break;
            }
        }
        reverse(a.begin()+i+1, a.end());
    }
};