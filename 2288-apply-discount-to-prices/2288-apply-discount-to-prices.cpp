class Solution {
public:
    string discountPrices(string s, int discount) {
        stringstream ss(s);
        string word, ans;
        int flag=0;
        vector<string>words;
        while (ss >> word) {
            flag=0;
            int n=word.size();
            if(n==1 || word[0]!='$'){
                ans+=word+" ";
            }else{
                long long price=0, i=0;
                for(i=1;i<n;i++){
                    if(!isdigit(word[i])){
                        flag=1;
                        ans+=word+" ";
                        break;
                    }
                    price=price*10+(word[i]-'0');
                }
                if(i>=n){
                stringstream ss2;
                double discounted=(100-discount)/100.0;
                ss2<<fixed<<setprecision(2)<<(discounted*price);
                ans+='$'+ss2.str()+" ";}
            }
        }
        ans.pop_back();
        return ans;
    }
};