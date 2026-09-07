class Solution {
public:
    bool sol(string &s,int idx,unordered_set<string>  &dict,vector<int> &dp){
        if(idx>=s.size())return true;
        if(dp[idx]!=-1)return dp[idx];

        string temp="";
        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(dict.count(temp)){
                if(sol(s,i+1,dict,dp))return dp[idx]= true;
            }
        }
        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int> dp(n,-1);
        return sol(s,0,dict,dp);
    }
};