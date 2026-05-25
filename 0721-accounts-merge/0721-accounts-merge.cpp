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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);
        unordered_map<string,int> mailAccount;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailAccount.find(mail)==mailAccount.end()){
                    mailAccount[mail]=i;
                }
                else{
                    dsu.Union(i,mailAccount[mail]);
                }
            }
        }
    vector<string> mergedMail[n];
        for(auto it:mailAccount){
            int node=it.second;
            string mail=it.first;
            int parent=dsu.find(node);
    mergedMail[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            vector<string> temp;
            if(mergedMail[i].empty())continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mergedMail[i].size();j++){
                temp.push_back(mergedMail[i][j]);
            }
            
            ans.push_back(temp);

        }
        return ans;
    }
};