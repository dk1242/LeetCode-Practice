class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>freq1(10, 0), freq2(10, 0);
        while(n){
            freq1[n%10]++;
            n/=10;
        }
        // for(auto it:freq1){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        for(int i=0;i<31;i++){
            int temp=(1<<i);
            // cout<<temp<<" ";
            while(temp){
                freq2[temp%10]++;
                temp/=10;
            }
            // for(auto it:freq2){
            //     cout<<it<<" ";
            // }
            // cout<<"\n";
            int flag=1;
            for(int i=0;i<10;i++){
                if(freq1[i]!=freq2[i]){
                    flag=0;
                }
            }
            if(flag)return true;
            for(int i=0;i<10;i++)
                freq2[i]=0;
        }
        return false;
    }
};