class Solution {
public:
    int sol(int i,int j,string a,string b,vector<vector<int>>& dp){
         int n=a.size();
    int m=b.size();
    if(i==n)return m-j;
    if(j==m)return n-i;
    if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]= sol(i+1,j+1,a,b,dp);
        return dp[i][j]= 1+min({sol(i+1,j,a,b,dp),sol(i,j+1,a,b,dp),sol(i+1,j+1,a,b,dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return sol(0,0,word1,word2,dp);
    }
};