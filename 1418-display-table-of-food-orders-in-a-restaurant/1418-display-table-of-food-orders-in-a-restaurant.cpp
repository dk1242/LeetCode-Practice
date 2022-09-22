class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<pair<string, string>, int>mp;
        set<string>dish;
        set<int>table;
        for(int i=0;i<orders.size();i++){
            mp[{orders[i][1], orders[i][2]}]++;
            dish.insert(orders[i][2]);
            table.insert(stoi(orders[i][1]));
        }
        vector<vector<string>>vs;
        vector<string>head;
        head.push_back("Table");
        for(auto it:dish)
            head.push_back(it);
        vs.push_back(head);
        for(auto it:table){
            // cout<<it<<" ";
            vector<string>temp;
            temp.push_back(to_string(it));
            for(auto i:dish){
                temp.push_back(to_string(mp[{to_string(it), i}]));
            }
            vs.push_back(temp);
        }
        return vs;
    }
};