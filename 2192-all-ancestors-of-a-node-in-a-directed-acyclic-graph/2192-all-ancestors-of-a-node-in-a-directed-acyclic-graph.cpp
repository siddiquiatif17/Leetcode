class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<set<int>> ans(n);
        for(int i=0;i<n;i++){ 
            if(indegree[i]==0){
                q.push(i);
                // ans[i].push_back({});
                
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
           
            for(int neigh:graph[node]){
                indegree[neigh]--;
               ans[neigh].insert(node);
                
                for(auto it:ans[node]){
                    ans[neigh].insert(it);
                }
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            res[i]=vector<int>(ans[i].begin(),ans[i].end());
        }
        return res;
    }
};