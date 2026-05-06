class Solution {
public:
    int sol(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
        int n=nums.size();
        if(target==0)return 1;
        if(i>=n)return 0;

        if(dp[i][target]!=-1)return dp[i][target];

        int pick = 0;
        if(nums[i] <= target) {
            pick = sol(nums, i+1, target - nums[i], dp);
        }

        int notPick=sol(nums,i+1,target,dp);
        return dp[i][target]= pick || notPick;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2!=0)return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));


        return sol(nums,0,sum/2,dp);
        
    }
};