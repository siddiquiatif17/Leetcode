class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;

        for(int i=0;i<n;i++)mpp[s[i]]=i;
        int lastIndex=0;
        int start=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            lastIndex=max(lastIndex,mpp[s[i]]);
            if(i==lastIndex){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
        
    }
};