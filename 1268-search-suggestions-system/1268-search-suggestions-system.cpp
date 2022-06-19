class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        string cur="";
        sort(products.begin(), products.end());
        for(int i=0;i<searchWord.length();i++){
            cur+=searchWord[i];
            vector<string>res;
            auto it = std::lower_bound(products.begin(), products.end(), cur);
            for(int j=0;j<3 && it+j!=products.end();j++){
                // cout<<products[j].substr(0, cur.length())<<" ";
                // if(cur==products[j].substr(0, cur.length())){
                string cand=*(it+j);
                // cout<<cand<<" "<<products[j]<<"\n";
                if(cand.find(cur)!=0)
                    break;
                res.push_back(cand);
                // }
            }
            ans.push_back(res);
        }
        return ans;
    }
};