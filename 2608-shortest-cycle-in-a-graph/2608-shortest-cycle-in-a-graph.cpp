class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int min_cycle = INT_MAX;

        for (int i = 0; i < n; ++i) {
            vector<int> distance(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            q.push(i);
            distance[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (distance[v] == -1) {
                        distance[v] = distance[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        
                        int cycle_length = distance[u] + distance[v] + 1;
                        min_cycle = min(min_cycle, cycle_length);
                    }
                }
            }
        }

        return (min_cycle != INT_MAX) ? min_cycle : -1;
    }
};