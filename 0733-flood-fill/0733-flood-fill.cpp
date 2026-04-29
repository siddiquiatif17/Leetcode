class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        if(original==color)return image;
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>>  q;
        q.push({sr,sc});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            image[row][col]=color;
            for(int k=0;k<4;k++){
                int newRow=row+dx[k];
                int newCol=col+dy[k];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==original){
                    q.push({newRow,newCol});
                    
                }
            }
        }
        return image;
    }
};