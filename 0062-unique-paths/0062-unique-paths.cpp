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
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int down=dp[i-1][j];
                int right=dp[i][j-1];
                dp[i][j]=down+right;
            }
        }
        // return sol(m,n,0,0,dp);
        return dp[m-1][n-1];
    }
};