class Solution {
public:
    int sol(vector<int>& nums,int target,int idx,vector<vector<int>>& dp,int offset){
        

    if(target > offset || target < -offset) return 0;

        if(idx==nums.size())return target==0;
        if(dp[idx][target+offset]!=-1)return dp[idx][target+offset];
        int pos=sol(nums,target-nums[idx],idx+1,dp,offset);
        int neg=sol(nums,target+nums[idx],idx+1,dp,offset);
        return dp[idx][target+offset]= pos+neg;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return sol(nums,target,0,dp,sum);
    }
};