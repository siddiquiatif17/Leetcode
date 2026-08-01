class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int size=edges.size();
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<size;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            graph[u].push_back({v,prob});
            graph[v].push_back({u,prob});
        }

       set<pair<double,int>, greater<pair<double,int>>> st;
        st.insert({1.0,start_node});
        vector<double> probArr(n,0.0000);
        probArr[start_node]=1.0;

        while(!st.empty()){
           auto temp=*st.begin();

            st.erase(st.begin());
            double prob = temp.first;
    int node = temp.second;

             if(prob < probArr[node]) continue;

            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                double neighProb=neigh.second;
                if(neighProb*prob>probArr[neighNode]){
                    probArr[neighNode]=neighProb*prob;
                    st.insert({neighProb*prob,neighNode});
                }
            }
        }
        return probArr[end_node];
    }
};