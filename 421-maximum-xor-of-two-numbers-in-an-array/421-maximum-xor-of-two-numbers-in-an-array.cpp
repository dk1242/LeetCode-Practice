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
    int findMaximumXOR(vector<int>& nums) {
        Trie* root=new Trie();
        int n=nums.size();
        for(int i=0;i<n;i++){
            // cout<<nums[i];
            root->insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, root->getMax(nums[i]));
        }
        return ans;
    }
};