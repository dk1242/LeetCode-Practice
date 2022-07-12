class Solution {
public:
    bool dfs(vector<int>&sides, vector<int>&match, int ind, int &sum){
        if(ind==match.size()){
            return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3] && sides[3]==sides[1];
        }
        for(int i=0;i<4;i++){
            if(sides[i]+match[ind]>sum)continue;
            sides[i]+=match[ind];
            if(dfs(sides, match, ind+1, sum))
                return true;
            sides[i]-=match[ind];
        }
        return false;
    }
    bool makesquare(vector<int>& match) {
        int n=match.size();
        int sum=accumulate(match.begin(), match.end(), 0);
        if(sum%4!=0)
            return false;
        sum/=4;
        sort(match.rbegin(), match.rend());
        vector<int>sides(4, 0);
        return dfs(sides, match, 0, sum);
    }
};