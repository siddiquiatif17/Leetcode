class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    bool Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        vector<int> ans;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(!dsu.Union(u,v)){
                ans={u,v};
            }
        }

        return ans;
        
    }
};