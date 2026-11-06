class Solution {
public:
    int sol(vector<vector<int>>& obstacle,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1 && obstacle[i][j]!=1)return 1;
        if(i>=n || j>=m)return 0;
        if(obstacle[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=sol(obstacle,i,j+1,n,m,dp);
        int right=sol(obstacle,i+1,j,n,m,dp);
        return dp[i][j]= down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return sol(obstacleGrid,0,0,n,m,dp);
    }
};