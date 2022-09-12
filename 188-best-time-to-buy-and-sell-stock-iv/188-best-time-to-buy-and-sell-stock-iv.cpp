class Solution {
public:
    unordered_map<string, int>mp;
    int fun(vector<int>&prices, int k, int canbuy, int cansell, int ind){
        if(k<=0 || ind==prices.size()){
            return 0;
        }
        if(ind==prices.size()-1){
            if(k<=0)
                return 0;
            if(canbuy==0 && cansell==1 ){
                return prices[ind];
            }else return 0;
        }
        string key=to_string(k)+"_"+to_string(canbuy)+"_"+to_string(cansell)+"_"+to_string(ind);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        if(canbuy==0){
            if(cansell)
                return mp[key]=max(prices[ind]+fun(prices, k-1, 1, 0, ind+1), fun(prices, k, 0, 1, ind+1));
            else return mp[key]=fun(prices, k, 0, 0, ind+1);
        }else{
            return mp[key]=max(-prices[ind]+fun(prices, k, 0, 1, ind+1), fun(prices, k, 1, 0, ind+1));
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        
        return max(fun(prices, k, 0, 0, 0), fun(prices, k, 1, 0, 0));
    }
};