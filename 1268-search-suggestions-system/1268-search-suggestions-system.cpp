class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        string cur="";
        sort(products.begin(), products.end());
        for(int i=0;i<searchWord.length();i++){
            cur+=searchWord[i];
            vector<string>res;
            for(int j=0;j<products.size();j++){
                // cout<<products[j].substr(0, cur.length())<<" ";
                if(cur==products[j].substr(0, cur.length())){
                    res.push_back(products[j]);
                }
                if(res.size()==3)
                    break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};