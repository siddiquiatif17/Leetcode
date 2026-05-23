class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &f : flights){
            graph[f[0]].push_back({f[1],f[2]});
        }

        vector<vector<int>> dist(
            n,
            vector<int>(k+2,1e9)
        );

        set<vector<int>> st;

        dist[src][0] = 0;

        st.insert({0,src,0});

        while(!st.empty()){

            auto cur = *st.begin();
            st.erase(st.begin());

            int cost  = cur[0];
            int node  = cur[1];
            int stops = cur[2];

            if(node == dst)
                return cost;

            if(stops == k+1)
                continue;

            for(auto &it : graph[node]){

                int neigh = it.first;
                int wt    = it.second;

                int newCost = cost + wt;

                if(newCost < dist[neigh][stops+1]){

                    dist[neigh][stops+1] = newCost;

                    st.insert({
                        newCost,
                        neigh,
                        stops+1
                    });
                }
            }
        }

        return -1;
    }
};