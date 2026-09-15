class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int prefixSum=0;
        mpp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(mpp.count(prefixSum-k))ans+=mpp[prefixSum-k];
            mpp[prefixSum]++;
        }
        return ans;
        
    }
};