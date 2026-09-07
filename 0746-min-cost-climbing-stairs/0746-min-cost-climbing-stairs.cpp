class Solution {
public:
    int sol(vector<int> & cost,int idx,vector<int> &dp){
        if(idx>=cost.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int singleStep=cost[idx]+sol(cost,idx+1,dp);
        int doubleStep=cost[idx]+sol(cost,idx+2,dp);
        return dp[idx]= min(singleStep,doubleStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(sol(cost,0,dp),sol(cost,1,dp));
        
    }
};