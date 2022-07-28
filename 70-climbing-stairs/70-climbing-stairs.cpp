class Solution {
public:
    int memo[46];
    Solution(){
    for(int i=0;i<46;i++)
        memo[i]=-1;
    }
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(memo[n]!=-1)
            return memo[n];
        return memo[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};