class Solution {
public:
    int sol(vector<int>& nums,int idx,int prevIndex,vector<vector<int>>& dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][prevIndex+1]!=-1)return dp[idx][prevIndex+1];
        int skip=sol(nums,idx+1,prevIndex,dp);
        int pick=0;
        if(prevIndex==-1 || nums[idx]>nums[prevIndex])pick=1+sol(nums,idx+1,idx,dp);
        return dp[idx][prevIndex+1]= max(pick,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return sol(nums,0,-1,dp);
        
    }
};