class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int>freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(freq.rbegin(), freq.rend());
        int ans=0, curr=0;
        for(int i=0;i<freq.size();i++){
            curr+=freq[i];
            ans++;
            if(curr>=n/2){
                return ans;
            }
        }
        return ans;
    }
};