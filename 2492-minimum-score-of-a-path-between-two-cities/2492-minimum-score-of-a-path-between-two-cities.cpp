class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        int size=roads.size();
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<size;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        
        queue<pair<int,int>> q;
        q.push({0,1});
        vector<int> visited(n+1,0);
        visited[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int node=temp.second;
            int wt=temp.first;
           
            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighWt=neigh.second;
                 ans=min(ans,neighWt);
                if(!visited[neighNode]){
                    visited[neighNode]=1;
                    q.push({neighWt,neighNode});
                }
            }
        }
        return ans;
    }
};