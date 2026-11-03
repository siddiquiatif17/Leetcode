class Solution {
public:
    bool sol(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
        int n=nums.size();
        if(i>=n)return false;
        if(target==0)return true;
        if(dp[i][target]!=-1)return dp[i][target];

        
        int notPick=sol(nums,i+1,target,dp);
        int pick=0;
        if(target-nums[i]>=0)
        pick=sol(nums,i+1,target-nums[i],dp);
        return dp[i][target]= pick|| notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return sol(nums,0,sum/2,dp);
        
    }
};