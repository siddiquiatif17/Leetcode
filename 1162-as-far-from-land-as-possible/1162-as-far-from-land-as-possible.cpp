class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        if(q.empty() || q.size()==n*n)
            return -1;

        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};

        int dist=-1;

        while(!q.empty()){

            int sz=q.size();
            dist++;

            while(sz--){

                auto [r,c]=q.front();
                q.pop();

                for(int k=0;k<4;k++){

                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nr<n &&
                       nc>=0 && nc<n &&
                       grid[nr][nc]==0){

                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return dist;
    }
};