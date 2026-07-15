class Solution {
public:
    long long sol(vector<int>& nums,int idx,bool plus,vector<vector<long long>>& dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][plus]!=-1)return dp[idx][plus];
        long long notPick=sol(nums,idx+1,plus,dp);
        long long pick;
        if(plus)pick=nums[idx]+sol(nums,idx+1,!plus,dp);
        else pick=-nums[idx]+sol(nums,idx+1,!plus,dp);
        return dp[idx][plus]= max(pick,notPick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return sol(nums,0, 1,dp);
        
    }
};