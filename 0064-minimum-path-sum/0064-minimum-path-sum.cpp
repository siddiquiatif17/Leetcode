class Solution {
public:
    int sol(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size();
        int m=grid[0].size();
      if(i>=n || j>=m)return 1e9;
      if(i==n-1 && j==m-1)return grid[i][j];
      if(dp[i][j]!=-1)return dp[i][j];
        
       int down=grid[i][j]+ sol(i+1,j,grid,dp);

        int right=grid[i][j]+ sol(i,j+1,grid,dp);
        return dp[i][j]= min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return sol(0,0,grid,dp);
    }
};