class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=1;
            for(int neigh:rooms[node]){
               if(!visited[neigh])q.push(neigh);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    }
};