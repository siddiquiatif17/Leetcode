class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

       
        int i=0;
        int j=0;
        int prevRow=0;
        int prevCol=0;
        while(i<n && j<m && i>=0 && j>=0 && !visited[i][j]){
            prevRow=i;
            prevCol=j;
            visited[i][j]=1;
            if(grid[i][j]=='R')j++;
            else if(grid[i][j]=='L')j--;
            else if(grid[i][j]=='U')i--;
            else i++;
        }    
        return {prevRow,prevCol};    
    }
};