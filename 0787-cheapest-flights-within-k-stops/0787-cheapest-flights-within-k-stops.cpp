class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<m;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            graph[u].push_back({v,cost});
        }

        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;

        set<pair<pair<int,int>,int>> st;
        st.insert({{0,src},0});

        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(temp);
            int node=temp.first.second;
            int cost=temp.first.first;
            int stops=temp.second;
            if(node==dst)return cost;
            if(stops>k)continue;

            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                int neighCost=neigh.second;
                if(cost+neighCost<INT_MAX){
                    if(cost+neighCost<dist[neighNode][stops+1]){
                        dist[neighNode][stops+1]=cost+neighCost;
                        st.insert({{dist[neighNode][stops+1],neighNode},stops+1});
                    }
                }
            }
        }
        return -1;
        
    }
};