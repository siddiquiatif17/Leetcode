class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
                int v=prerequisites[i][1];
                graph[u].push_back(v);
                
                indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neigh:graph[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]!=0)return false;
        }
        return true;
    }
};