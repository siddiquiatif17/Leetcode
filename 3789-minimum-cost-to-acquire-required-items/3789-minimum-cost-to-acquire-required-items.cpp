class Solution {
public:
    long long sol(int cost1,int cost2,int costBoth,int need1,int need2,vector<vector<long long>>& dp){
        if(need1<=0 && need2<=0)return 0;
        long long first = LLONG_MAX;
        long long second = LLONG_MAX;
        long long both = LLONG_MAX;
        if(dp[need1][need2]!=-1)return dp[need1][need2];
       if(need1>0) first=cost1+sol(cost1,cost2,costBoth,need1-1,need2,dp);
    if(need2>0) second=cost2+sol(cost1,cost2,costBoth,need1,need2-1,dp);
        both=costBoth+sol(cost1,cost2,costBoth,max(0,need1-1),max(0,need2-1),dp);
        return dp[need1][need2]= min({first,second,both});
    }
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // vector<vector<long long>> dp(need1+1,vector<long long>(need2+1,-1));
        // return sol(cost1,cost2,costBoth,need1,need2,dp);

        long long ans=0;
        long long common=min(need1,need2);
        ans+=1LL*common*min(costBoth,cost1+cost2);
        need1-=common;
        need2-=common;

        ans+=1LL*need1*min(cost1,costBoth);
        ans+=1LL*need2*min(cost2,costBoth);
        return ans;


    }
};