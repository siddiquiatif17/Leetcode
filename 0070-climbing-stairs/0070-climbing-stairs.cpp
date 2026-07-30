class Solution {
public:
    int sol(int idx,int n,vector<int> &dp){
        if(idx>n)return 0;
        if(idx==n)return 1;

        if(dp[idx]!=-1)return dp[idx];

        int singleStep=sol(idx+1,n,dp);
        int doubleStep=sol(idx+2,n,dp);
        return dp[idx]= singleStep+doubleStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return sol(0,n,dp);
    }
};