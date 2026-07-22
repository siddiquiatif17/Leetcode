class Solution {
public: 
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int n,m;
    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>>& visited){
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]=='1'){
                dfs(grid,newRow,newCol,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
            int cnt=0;
            vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};