class Solution {
public:
    int sol(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        int n=a.size();
        int m=b.size();
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]= 1+sol(a,b,i+1,j+1,dp);
        }
        return dp[i][j]= max(sol(a,b,i+1,j,dp),sol(a,b,i,j+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return sol(text1,text2,0,0,dp);
    }
};