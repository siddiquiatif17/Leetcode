class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
         dist[0][0]=0;

        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(st.begin());
            int wt=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            if(row==n-1 && col==m-1)return wt;
            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                
                if(newRow>=0 && newRow<n &&  newCol>=0 && newCol<m){
                       int edgeEffort=abs(heights[row][col]-heights[newRow][newCol]);
                       int newDist=max(wt,edgeEffort);
                   
                    if(newDist<dist[newRow][newCol]){
                        dist[newRow][newCol]=newDist;
                        st.insert({newDist,{newRow,newCol}});
                    }
                }
            }
        }

        return 0;
    }
};