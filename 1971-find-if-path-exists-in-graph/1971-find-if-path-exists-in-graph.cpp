class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,vector<int> &visited){
        visited[node]=1;
        for(int neigh:graph[node]){
            if(!visited[neigh]){
                dfs(graph,neigh,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m=edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n,0);
        dfs(graph,source,visited);
        return visited[destination];
        
    }
};