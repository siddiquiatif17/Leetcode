class Solution {
public: 
    void dfs(vector<vector<int>> & isConnected,int node,vector<int>& visited){
        visited[node]=1;
        for(int neigh=0;neigh<isConnected.size();neigh++){
            if(!visited[neigh] && isConnected[node][neigh]==1)dfs(isConnected,neigh,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        // vector<vector<int>> graph(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1)graph[i].push_back(j);
        //     }
        // }
        int cnt=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                cnt++;
            }
        }
    return cnt;
        
    }
};