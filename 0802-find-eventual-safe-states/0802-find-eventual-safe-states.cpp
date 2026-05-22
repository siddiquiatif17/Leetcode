class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> reverted(n);
        vector<int> outdegree(n);
        for(int i=0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                reverted[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node =q.front();
            q.pop();
            for(int neigh:reverted[node]){
                outdegree[neigh]--;
                if(outdegree[neigh]==0)q.push(neigh);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0)ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};