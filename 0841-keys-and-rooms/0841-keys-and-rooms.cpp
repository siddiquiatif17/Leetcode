class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,vector<int>& visited){
        visited[node]=1;
        for(int neigh:graph[node]){
            if(!visited[neigh]){
                dfs(graph,neigh,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                graph[i].push_back(rooms[i][j]);   
          }
        }

        vector<int> visited(n,0);
        dfs(graph,0,visited);
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    
        
    }
};