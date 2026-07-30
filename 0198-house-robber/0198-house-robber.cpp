class Solution {
public:
    int sol(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
       
        int notPick=sol(nums,idx+1,dp);
        int pick=nums[idx]+sol(nums,idx+2,dp);
        return dp[idx]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
        
    }
};