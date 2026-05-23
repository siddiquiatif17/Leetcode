class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(
            n,
            vector<int>(m,1e9)
        );

        set<pair<int,pair<int,int>>> st;

        dist[0][0]=0;
        st.insert({0,{0,0}});

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!st.empty()){

            auto it=*st.begin();
            st.erase(st.begin());

            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int i=0;i<4;i++){

                int newRow=row+dx[i];
                int newCol=col+dy[i];

                if(newRow>=0 && newRow<n &&
                   newCol>=0 && newCol<m){

                    int wt=
                    abs(
                        heights[newRow][newCol]
                        -
                        heights[row][col]
                    );

                    int newEffort=max(diff,wt);

                    if(newEffort<
                       dist[newRow][newCol]){

                        if(dist[newRow][newCol]!=1e9){
                            st.erase({
                                dist[newRow][newCol],
                                {newRow,newCol}
                            });
                        }

                        dist[newRow][newCol]
                        =
                        newEffort;

                        st.insert({
                            newEffort,
                            {newRow,newCol}
                        });
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};