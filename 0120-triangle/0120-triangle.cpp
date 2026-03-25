class Solution {
public:
int m,n;

    int sol(vector<vector<int>> &triangle,int i,int j,vector<vector<int>>& dp){
        if(i==m-1)return triangle[i][j];
       
        if(dp[i][j]!=-1)return dp[i][j];

        int down=triangle[i][j]+sol(triangle,i+1,j,dp);
        int downRight=triangle[i][j]+sol(triangle,i+1,j+1,dp);
        return dp[i][j]= min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        n=triangle[m-1].size();
        vector<vector<int>> dp=triangle;
       for(int i=m-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int down=triangle[i][j]+dp[i+1][j];
            int downRight=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,downRight);
        }
       }
       return dp[0][0];
        // return sol(triangle,0,0,dp);

    }
};