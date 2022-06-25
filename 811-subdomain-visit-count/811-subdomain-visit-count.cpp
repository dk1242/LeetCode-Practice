class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for (auto it : cpdomains) {
            int i = it.find(" ");
            int n = stoi(it.substr(0, i));
            string s = it.substr(i+1);
            for (int i=0; i<s.size(); i++)
                if (s[i] == '.')
                    mp[s.substr(i + 1)] += n;
            mp[s] += n;
        }
        vector<string>res;
        for (auto it:mp)
            res.push_back(to_string(it.second)+" "+it.first);
        return res;
    }
};