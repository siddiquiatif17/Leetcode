class Solution {
public:
    int sol(vector<int>& nums,int idx,int k,vector<int>& dp){
        int n=nums.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int maxi=0;
        int result=0;
        for(int i=idx;i<n && i-idx+1<=k;i++){
            maxi=max(maxi,nums[i]);
           result=max(result,((i-idx+1)*maxi)+sol(nums,i+1,k,dp));
        }
        return dp[idx]= result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return sol(arr,0,k,dp);

        
    }
};