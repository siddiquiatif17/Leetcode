class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = 1;

        // right
        if(j + 1 < m && !visited[i][j+1] && grid[i][j+1] == '1')
            dfs(i, j+1, grid, visited);

        // down
        if(i + 1 < n && !visited[i+1][j] && grid[i+1][j] == '1')
            dfs(i+1, j, grid, visited);

        // up
        if(i - 1 >= 0 && !visited[i-1][j] && grid[i-1][j] == '1')
            dfs(i-1, j, grid, visited);

        // left
        if(j - 1 >= 0 && !visited[i][j-1] && grid[i][j-1] == '1')
            dfs(i, j-1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};