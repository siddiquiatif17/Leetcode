class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int time=times[i][2];
            graph[u].push_back({v,time});
        }

        vector<int> dist(n+1,1e9);
        dist[k]=0;
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto it=*st.begin();
            st.erase(st.begin());
            int node=it.second;
            int wt=it.first;
            for(auto it:graph[node]){
                int neigh=it.first;
                int neighWt=it.second;
                if(wt+neighWt<dist[neigh]){
                    if(dist[neigh]!=1e9){
                        st.erase({dist[neigh],neigh});
                    }
                        dist[neigh]=wt+neighWt;
                        st.insert({dist[neigh],neigh});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
};