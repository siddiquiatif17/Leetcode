class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int time=roads[i][2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }
        
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;

        set<pair<long long,int>> st;
        st.insert({0,0});
        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(temp);
            long long time=temp.first;
            int node=temp.second;
            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighDist=neigh.second;
                if(time+neighDist<LLONG_MAX){
                    if(time+neighDist<dist[neighNode]){
                        st.erase({dist[neighNode],neighNode});
                        dist[neighNode]=time+neighDist;
                        st.insert({dist[neighNode],neighNode});
                        ways[neighNode]=ways[node];
                    }
                   else if(time+neighDist==dist[neighNode]){
                        ways[neighNode]=(ways[neighNode]+ways[node])%MOD;
                    }
                    
                }
            }
        }
        return ways[n-1]%MOD;
    }
};