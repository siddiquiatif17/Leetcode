class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> mpp;

        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mpp[strs[i]].push_back(temp);
        }
        vector<vector<string>> result;
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
        
    }
};