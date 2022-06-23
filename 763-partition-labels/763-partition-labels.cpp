class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char, int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int max=mp[s[0]], prev=-1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i==max){
                ans.push_back(max-prev);
                prev=max;
                if(i<n-1)
                    max=mp[s[i+1]];
            }
            else if(mp[s[i]]>max){
                max=mp[s[i]];
            }
        }
        if(max==n-1 && max!=prev)
            ans.push_back(max-prev);
        return ans;
    }
};