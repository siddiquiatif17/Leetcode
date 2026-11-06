class Solution {
public:
    int sol(vector<int>& nums,int idx,vector<int>& dp){
        int n=nums.size();
        if(idx>=n)return 0;
        if(idx==n-1)return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        int result=1e9;
        for(int i=1;i<=nums[idx];i++){
          if(i<n)  result=min(result,1+sol(nums,i+idx,dp));
        }
        return dp[idx]= result;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(nums,0,dp);
    }
};