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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,i,visited);
                cnt++;
            }
        }
        return cnt;


        
    }
};