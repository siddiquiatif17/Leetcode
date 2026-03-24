// class Solution {
// public:
//     const int mod= 1e9+7;
//     int sol(string s,int k,int idx,vector<int>& dp){
//         if(idx>=s.size())return 1;
//         if (s[idx] == '0') return 0;
//         if(dp[idx]!=-1)return dp[idx];
//         long num = 0;
//         int ans=0;
//         for(int i=idx;i<s.size();i++){
//             num = num * 10 + (s[i] - '0');
//             // if(stoi(p)<1 ||  stoi(p)>k)break;
//             if(num>k)break;
//            ans=(ans+sol(s,k,i+1,dp))%mod;
//         }
//         return dp[idx]= ans%mod;
//     }
//     int numberOfArrays(string s, int k) {
//         int n=s.size();
//         vector<int> dp(n,-1);
//         return sol(s,k,0,dp);
        
//     }
// };

class Solution {
public:
    const int mod = 1e9+7;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        dp[n] = 1; // base case

        for(int idx = n-1; idx >= 0; idx--) {

            if(s[idx] == '0') continue;

            long num = 0;

            for(int i = idx; i < n; i++) {
                num = num * 10 + (s[i] - '0');

                if(num > k) break;

                dp[idx] = (dp[idx] + dp[i+1]) % mod;
            }
        }

        return dp[0];
    }
};