class Trie{
  public:
    Trie *child[2];
    Trie(){
        Trie* curr=this;
        curr->child[0]=NULL;
        curr->child[1]=NULL;
    }
    void insert(int num){
        Trie*curr = this;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) &1;
            if(!curr->child[bit]){
                curr->child[bit]=new Trie();
            }
            curr=curr->child[bit];
        }
    }
    int getMax(int num){
        Trie* curr=this;
        int maxm=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->child[!bit]){
                maxm=maxm|(1<<i);
                curr=curr->child[!bit];
            }
            else
            curr=curr->child[bit];
        }
        return maxm;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>>q;
        Trie* root=new Trie();
        int i=0;
        for(auto it:queries){
            q.push_back({it[1], it[0], i++});
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        int j = 0;
        vector<int> res(queries.size());
        for(auto &it:q){
            int x=it[1];
            int lim=it[0];
            while(j<n && nums[j]<=lim){
                root->insert(nums[j]);
                j++;
            }
            if(j)
            res[it[2]]=root->getMax(x);
            else res[it[2]]=-1;
        }
        return res;
    }
};