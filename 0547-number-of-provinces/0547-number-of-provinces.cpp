class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        visited[node]=1;
        for(int neigh:graph[node]){
            if(!visited[neigh]){
                dfs(neigh,graph,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
             if(isConnected[i][j]==1){
                   graph[i].push_back(j);
                graph[j].push_back(i);
             }
            }
        }
        int count=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,graph,visited);
            }
        }
    return count;
        
    }
};