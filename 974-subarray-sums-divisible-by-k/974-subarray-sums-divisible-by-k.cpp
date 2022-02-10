class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
	int ans=0, sum=0, l=0, r=0;
	mp[0]=1;
	for(int it:nums){
		sum=(sum+it)%k;
		if(sum<0)
			sum+=k;
		ans+=mp[sum];
		mp[sum]++;
	}
        return ans;
    }
};