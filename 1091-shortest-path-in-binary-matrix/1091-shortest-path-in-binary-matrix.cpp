class Solution {
public:
     int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        int src=grid[0][0];
        if(src!=0)return -1;
        q.push({0,src});
        grid[0][src]=1;
        int level=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){

            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            if(row==n-1 && col==n-1)return level;
            for(int i=0;i<8;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==0){
                    q.push({newRow,newCol});
                    grid[newRow][newCol]=1;
                }
            }
            }
            level++;
        }
        return -1;
    }
};