class Solution {
public:
    int sol(string &s,int idx,vector<int>& dp){
        if(idx>=s.size())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];
        int singleChar=sol(s,idx+1,dp);
        int doubleChar=0;
        if(stoi(s.substr(idx,2))>9 && stoi(s.substr(idx,2))<=26)doubleChar=sol(s,idx+2,dp);
        return dp[idx]= singleChar+doubleChar;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return sol(s,0,dp);
    }
};