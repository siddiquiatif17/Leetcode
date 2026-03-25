class Solution {
public:
    int sol(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int pick=nums[idx]+sol(nums,idx+2,dp);
        int notPick=sol(nums,idx+1,dp);
        return dp[idx]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(nums,0,dp);
        
    }
};