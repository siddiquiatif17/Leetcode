class Solution {
public:
int m,n;
int sol(vector<vector<int>>& grid,int i ,int j,vector<vector<int>>& dp){
    if(i==m-1 && j==n-1)return (grid[i][j]==1)?0:1;
    if(i>=m || j>=n || grid[i][j]==1)return 0;
if(dp[i][j]!=-1)return dp[i][j];
    int down=sol(grid,i+1,j,dp);
    int right=sol(grid,i,j+1,dp);
    return dp[i][j]= down+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(obstacleGrid,0,0,dp);
    }
};