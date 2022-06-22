class Solution {
public:
    int minPartitions(string n) {
        int l=n.length();
        char ans='0';
        for(int i=0;i<l;i++){
            if((ans)<(n[i]))
                ans=n[i];
        }
        return ans-'0';
    }
};