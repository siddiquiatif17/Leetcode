class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)q.push({i,j});
                else mat[i][j]=-1;
            }
        }

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && mat[newRow][newCol]==-1){
                    mat[newRow][newCol]=mat[row][col]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return mat;
    }
};