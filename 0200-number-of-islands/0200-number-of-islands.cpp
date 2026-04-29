class Solution {
public:
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void dfs(int row,int col,vector<vector<char>> &grid){
    grid[row][col]='0';
    for(int k=0;k<4;k++){
    int newRow=row+dx[k];
    int newCol=col+dy[k];
    if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol]=='1')dfs(newRow,newCol,grid);
    }
    
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};