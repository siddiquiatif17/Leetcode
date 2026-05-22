class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int  node=q.front();
            q.pop();
            topo.push_back(node);
            for(int neigh:graph[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
        //  if(topo.size() != numCourses)
        //     return {};
        return (topo.size()!=numCourses)?vector<int>{}:topo;
        
    }
};