class Solution {
public:
    int sol(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int notRob=sol(nums,idx+1,dp);
        int rob=nums[idx]+sol(nums,idx+2,dp);
        return dp[idx]= max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(nums,0,dp);
    }
};