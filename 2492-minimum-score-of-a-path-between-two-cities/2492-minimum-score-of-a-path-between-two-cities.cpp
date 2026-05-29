class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        vector<int> visited(n+1,0);
        queue<int> q;
           q.push(1);
           visited[1]=1;
    int ans=INT_MAX;
        while(!q.empty()){
            int  node=q.front();
            q.pop();
            for(auto &[neigh, wt] : graph[node]){
                ans=min(ans,wt);
                if(!visited[neigh]){
                    visited[neigh]=1;
                    q.push(neigh);
                }
            }
        }
        return ans;
        
    }
};