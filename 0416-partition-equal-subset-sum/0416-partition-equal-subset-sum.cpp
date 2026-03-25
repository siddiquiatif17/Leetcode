class Solution {
public:
    bool sol(vector<int>& nums,int idx,int target,vector<vector<int>>& dp){
        if(target==0)return true;
        if(idx==nums.size())return false;
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool take = false;
        if(nums[idx] <= target)
            take = sol(nums, idx+1, target - nums[idx], dp);
        bool notTake=sol(nums,idx+1,target,dp);
        return dp[idx][target]= take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2==1)return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return sol(nums,0,sum/2,dp);
        
    }
};