class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int size=edges.size();
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<size;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double weight=succProb[i];
            graph[u].push_back({v,weight});
            graph[v].push_back({u,weight});
        }

        set<pair<double,int>, greater<pair<double,int>>> st;
        st.insert({1.0,start});
        vector<double> prob(n,0.0);
        while(!st.empty()){
            auto temp=*st.begin();
            st.erase(*st.begin());
            int node=temp.second;
            double wt=temp.first;
            for(auto neigh:graph[node]){
                int neighNode=neigh.first;
                double neighWt=neigh.second;
                if(wt*neighWt>prob[neighNode]){
                    prob[neighNode]=wt*neighWt;
                    st.insert({wt*neighWt,neighNode});
                }
            }
        }
        return prob[end];
    }
};