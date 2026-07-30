class Solution {
public:
    int ans=INT_MIN;
    int sol(int idx,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==nums.size())return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int notPick=sol(idx+1,prev,nums,dp);
        int pick=INT_MIN;
        if(prev==-1 || nums[idx]>nums[prev]){
            pick=1+sol(idx+1,idx,nums,dp);
        }
        return dp[idx][prev+1]= max(pick,notPick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return sol(0,-1,nums,dp);

        
    }
};