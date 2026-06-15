class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            graph[u].push_back({v,wt});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(temp);
            int time=temp.first;
            int node=temp.second;
            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighDist=neigh.second;
                if(time+neighDist<INT_MAX){
                    if(time+neighDist<dist[neighNode]){
                        dist[neighNode]=time+neighDist;
                        st.insert({dist[neighNode],neighNode});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dist[i]);
        }
        return maxi;
        
    }
};