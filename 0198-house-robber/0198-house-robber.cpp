class Solution {
public:
int n;
    int sol(vector<int>& nums,int idx,vector<int>& dp){
        if(idx==n)return 0;
        if(idx==n-1)return nums[idx];

        if(dp[idx]!=-1)return dp[idx];
        int pick=nums[idx]+sol(nums,idx+2,dp);
        int notPick=sol(nums,idx+1,dp);
        return dp[idx]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n,-1);
        return sol(nums,0,dp);

        
        
    }
};