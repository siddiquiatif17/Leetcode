class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        int m=times.size();

        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int time=times[i][2];
            graph[u].push_back({v,time});
        }

        set<pair<int,int>> st;
        st.insert({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(st.begin());
            int node=temp.second;
            int time=temp.first;

            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighTime=neigh.second;
                if(time+neighTime<dist[neighNode]){
                    dist[neighNode]=time+neighTime;
                    st.insert({time+neighTime,neighNode});
                }
            }
        }
        int ans=0;
     
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
        
        
    }
};