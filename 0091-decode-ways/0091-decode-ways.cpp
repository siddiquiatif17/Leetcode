class Solution {
public:
    int sol(string &s,int idx,vector<int> &dp){
        int n=s.size();
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];
        int singlePartition=sol(s,idx+1,dp);
        int doublePartition=0;
        if(idx+1<n){
            int num=((s[idx]-'0')*10)+(s[idx+1]-'0');
            if(num>=10 && num<=26){
                doublePartition=sol(s,idx+2,dp);
            }
        }
        return dp[idx]= singlePartition+doublePartition;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return sol(s,0,dp);
        
    }
};