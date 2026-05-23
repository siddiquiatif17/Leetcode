class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
             const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int time=roads[i][2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        
        set<pair<long long,int>> st;
        st.insert({0,0});
        vector<long long> dist(n,1e18);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        

        while(!st.empty()){
            auto it=*st.begin();
            st.erase(st.begin());
            int node=it.second;
            long long cost=it.first;
            for(auto  it:graph[node]){
                int neigh=it.first;
                int neighCost=it.second;
                long long newDist=cost+neighCost;
                if(newDist<dist[neigh]){
                    if(dist[neigh]!=1e18)
                    st.erase({dist[neigh],neigh});
                    
                ways[neigh]=ways[node];
                    
                dist[neigh]=newDist;
                st.insert({dist[neigh],neigh});
                }else if(dist[neigh]==newDist){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
        
    }
};