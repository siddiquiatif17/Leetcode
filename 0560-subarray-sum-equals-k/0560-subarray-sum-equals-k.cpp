class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
       unordered_map<int,int> mpp;
       mpp[0]=1;
       int prefixSum=0;
       for(int i=0;i<n;i++){
            prefixSum+=nums[i];
           
            if(mpp.find(prefixSum-k)!=mpp.end()){
                ans+=mpp[prefixSum-k];
            }
            mpp[prefixSum]++;
       }
        return ans;
        
    }
};