class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    void solve(vector<vector<char>>& board) {
        int  n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1 ){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                    }
                   
                }
            }
        }

        while(!q.empty()){
         auto temp=q.front();
         q.pop();
         int row=temp.first;
         int col=temp.second;
                board[row][col]='#';
         for(int i=0;i<4;i++){
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && board[newRow][newCol]=='O'){
                q.push({newRow,newCol});
            }
         }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }


        
    }
};