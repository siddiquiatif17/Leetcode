class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        queue<int> q;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]!=0)return false;
        }
        return true;
    }
};