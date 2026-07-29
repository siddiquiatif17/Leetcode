class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

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
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh:graph[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
         for(int i=0;i<numCourses;i++)if(indegree[i]!=0)return {};
        return ans;
    }
};