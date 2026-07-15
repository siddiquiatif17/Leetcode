class Solution {
public:
long long sol(vector<vector<int>>&questions,int idx,vector<long long> &dp){
    int n=questions.size();
    if(idx==n)return 0;
    if(dp[idx]!=-1)return dp[idx];

    long long skip=sol(questions,idx+1,dp);
    // int brainPower=questions[idx][1];

    long long solve=questions[idx][0];
    if(idx+questions[idx][1]+1<n)solve+=sol(questions,idx+questions[idx][1]+1,dp);
    return dp[idx]= max(skip,solve);
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            long long skip=dp[i+1];
            long long solve=questions[i][0];
           if(i+questions[i][1]+1<n)solve+= dp[i+questions[i][1]+1];
            dp[i]=max(skip,solve);
        }
        return dp[0];
        // return sol(questions,0,dp);
        
    }
};