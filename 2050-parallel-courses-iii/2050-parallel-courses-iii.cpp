class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        int m=relations.size();
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1,0);
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            int u=relations[i][0];
            int v=relations[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            
            if(indegree[i]==0){
                q.push(i);
                dp[i]=time[i-1];
            }
        }
        
        while(!q.empty()){
                int node=q.front();
                q.pop();
                
           
           
            for(int neigh:graph[node]){
                indegree[neigh]--;
                dp[neigh]=max(dp[neigh],dp[node]+time[neigh-1]);
                if(indegree[neigh]==0)q.push(neigh);
            }
           
            
        }
        return *max_element(dp.begin(),dp.end());
    }
};