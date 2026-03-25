class Solution {
public:
    int sol(int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>m-1 || j>n-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=sol(m,n,i+1,j,dp);
        int right=sol(m,n,i,j+1,dp);
        return dp[i][j]= down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(m,n,0,0,dp);
    }
};