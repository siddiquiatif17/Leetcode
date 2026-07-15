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
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
       
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][1],(long long)nums[i]+dp[i+1][0]);
            dp[i][0]=max(dp[i+1][0],-(long long)nums[i]+dp[i+1][1]);
        }
        return  dp[0][1];
        
    }
};