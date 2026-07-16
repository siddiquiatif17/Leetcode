class Solution {
public:
    bool isPred(string &a, string &b){
        if(b.size() != a.size() + 1) return false;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return i == a.size();
    }

    int sol(vector<string>& words,int idx,int prev,
            vector<vector<int>>& dp){

        if(idx == words.size()) return 0;

        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];

        int skip = sol(words,idx+1,prev,dp);

        int pick = 0;

        if(prev == -1 || isPred(words[prev],words[idx]))
            pick = 1 + sol(words,idx+1,idx,dp);

        return dp[idx][prev+1] = max(pick,skip);
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),
             [](string &a,string &b){
                 return a.size() < b.size();
             });

        int n = words.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return sol(words,0,-1,dp);
    }
};