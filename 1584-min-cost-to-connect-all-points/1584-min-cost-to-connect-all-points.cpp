class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=(abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]));
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        int count=0;
        vector<int> visited(n,0);
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int node=top.second;
            int wt=top.first;

            if(visited[node])continue;
            visited[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int neighWt=it.first;
                int neigh=it.second;
                if(!visited[neigh]){
                    pq.push({neighWt,neigh});
                }
            }
        }
        return sum;
        
    }
};