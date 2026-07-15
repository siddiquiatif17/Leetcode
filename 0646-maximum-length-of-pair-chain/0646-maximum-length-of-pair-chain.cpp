class Solution {
public:
    int sol(vector<vector<int>>& pairs,int idx,int prev,vector<vector<int>>& dp){
        if(idx>=pairs.size())return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int skip=sol(pairs,idx+1,prev,dp);
        int pick=0;
        if(prev==-1 || pairs[prev][1]<pairs[idx][0])pick=1+sol(pairs,idx+1,idx,dp);
        return dp[idx][prev+1]= max(skip,pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sol(pairs,0,-1,dp);
        
    }
};