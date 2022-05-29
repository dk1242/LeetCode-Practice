class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0, f=0;
        for(int i=0;i<n;i++){
            sort(words[i].begin(), words[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string intersect="";
                set_intersection(words[i].begin(), words[i].end(), words[j].begin(), words[j].end(), std::back_inserter(intersect));
                // cout<<intersect<<"@ ";
                if(intersect.length()==0){
                    int l1=words[i].length(), l2=words[j].length();
                    // cout<<words[i]<<" "<<words[j]<<" ";
                    ans=max(ans, l1*l2);
                }
            }
        }
        return ans;
    }
};