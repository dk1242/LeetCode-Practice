class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
	map<int,int>mp;
	int ans=0, sum=0, l=0, r=0;
	mp[0]=1;
	for(int it:nums){
		sum=(sum+it);
		ans+=mp[sum-k];
		mp[sum]++;
	}
        return ans;
    }
};