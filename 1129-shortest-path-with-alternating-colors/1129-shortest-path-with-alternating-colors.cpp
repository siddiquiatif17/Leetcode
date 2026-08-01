class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int r=redEdges.size();
        int b=blueEdges.size();

        vector<vector<pair<int,bool>>> graph(n);
        for(int i=0;i<r;i++){
            int u=redEdges[i][0];
            int v=redEdges[i][1];
            graph[u].push_back({v,1});
        }

        for(int i=0;i<b;i++){
            int u=blueEdges[i][0];
            int v=blueEdges[i][1];
            graph[u].push_back({v,0});
        }

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        q.push({{0,1},0});

         vector<vector<int>> visited(n,vector<int>(2,0));
        visited[0][0]=1;
        visited[0][1]=1;

        vector<int> ans(n,-1);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first.first;
            int color=it.first.second;
            int dist=it.second;

            if(ans[node] == -1)
    ans[node] = dist;

            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighColor=neigh.second;
                if(neighColor!=color && !visited[neighNode][neighColor]){
                    visited[neighNode][neighColor]=1;
                    q.push({{neighNode,neighColor},dist+1});
                }
            }             

        }
        
        return ans;
    }
};