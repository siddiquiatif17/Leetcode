class Solution {
public:
    int sol(vector<int>& coins,int idx,int amount,vector<vector<int>>& dp){
        if(amount==0)return 0;
        if(idx==coins.size())return 1e9;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int notPick=sol(coins,idx+1,amount,dp);
        int pick=1e9;
        if(amount-coins[idx]>=0)pick= 1+sol(coins,idx,amount-coins[idx],dp);
        return dp[idx][amount]= min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= sol(coins,0,amount,dp);
        return(ans>=1e9)?-1:ans;
        

    }
};