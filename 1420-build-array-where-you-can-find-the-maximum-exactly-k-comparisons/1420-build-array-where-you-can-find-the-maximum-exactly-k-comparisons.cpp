class Solution {
public:
int N,M,K;
int MOD=1e9+7;

    int sol(int idx,int searchCost,int maxi,vector<vector<vector<int>>>& dp){
        if(searchCost > K) return 0;
        if(idx==N){
            if(searchCost==K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][searchCost][maxi]!=-1)return dp[idx][searchCost][maxi];
                long long result=0;
        for(int i=1;i<=M;i++){
            if(i>maxi){
                result+=sol(idx+1,searchCost+1,i,dp);
            }else{
                result+=sol(idx+1,searchCost,maxi,dp);
            }
        }
        return dp[idx][searchCost][maxi]= result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
        return sol(0,0,0,dp);
    }
};