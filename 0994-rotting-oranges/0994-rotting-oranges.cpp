class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }

        int time=0;
        while(!q.empty()){
            int size=q.size();
              bool changed=false; 
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                int row=temp.first;
                int col=temp.second;
                for(int k=0;k<4;k++){
                    int newRow=row+dx[k];
                    int newCol=col+dy[k];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1){
                        q.push({newRow,newCol});
                        grid[newRow][newCol]=2;
                        fresh--;
                         changed=true;
                    }
                }
            }
           if(changed) time++;
        }

        return fresh==0?time:-1;
        
    }
};