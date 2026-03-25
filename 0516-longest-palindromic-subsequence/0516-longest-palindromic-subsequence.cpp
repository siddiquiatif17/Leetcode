class Solution {
public:
    int sol(string &s,int i,int j,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(i==j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j])return 2+sol(s,i+1,j-1,dp);
        return dp[i][j]= max(sol(s,i+1,j,dp),sol(s,i,j-1,dp));

    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sol(s,0,n-1,dp);
    }
};