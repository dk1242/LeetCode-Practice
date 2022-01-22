class Solution {
public:
    int bob=0, alice=0;
    map<pair<int, int>, int>mp;
    int stoneGameCalc(vector<int>& piles, int si, int ei, bool turn){
        if(ei<si)
            return 0;
        if(mp[{si, ei}]){
            return mp[{si, ei}];
        }
        if(turn){
            int a1=stoneGameCalc(piles, si+1, ei, false)+piles[si];
            int a2=stoneGameCalc(piles, si, ei-1, false)+piles[ei];
            alice+=max(a1, a2);
            return mp[{si, ei}]=max(a1, a2);
        }else{
            int b1=stoneGameCalc(piles, si+1, ei, true)-piles[si];
            int b2=stoneGameCalc(piles, si, ei-1, true)-piles[ei];
            bob+=min(b1, b2);
            return mp[{si, ei}]=min(b1, b2);
        }
    }
    bool stoneGame(vector<int>& piles) {
        bool turn=true;
        stoneGameCalc(piles, 0, piles.size()-1, turn);
        return alice>bob;
    }
};