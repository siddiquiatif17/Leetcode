class Solution {
public:
    bool possible(int k,string& s,string& p,vector<int>& removable){
        // unordered_map<int,int> mpp;
        vector<bool> removed(s.size(),false);
        for(int i=0;i<k;i++)removed[removable[i]]=true;
        string newString="";
        for(int i=0;i<s.size();i++){
            if(!removed[i])newString+=s[i];
        }
        int i=0;
        int j=0;
        while(i<newString.size() && j<p.size()){
            if(newString[i]==p[j]){
                i++;
                j++;
            }else i++;
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0;
        int high=removable.size();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,s,p,removable)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};