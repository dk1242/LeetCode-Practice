class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0, f=0;
        vector<int>mask(n, 0);
        for(int i=0;i<n;i++){
            for(auto it:words[i])
                mask[i]=mask[i]|(1<<(it-'a'));
            // cout<<mask[i]<<" "<<bitset<26>(mask[i]).to_string()<<" ";
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    int l1=words[i].length(), l2=words[j].length();
                    // cout<<words[i]<<" "<<words[j]<<" ";
                    ans=max(ans, l1*l2);
                }
            }
        }
        return ans;
    }
};