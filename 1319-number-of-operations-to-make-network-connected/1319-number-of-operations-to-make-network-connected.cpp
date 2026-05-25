class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return;
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
         if(m < n - 1) return -1;
        DSU dsu(n);
        int cnt=0;
        for(int i=0;i<m;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            dsu.Union(u,v);
        }
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i)cnt++;
        }
        return cnt-1;
        
    }
};