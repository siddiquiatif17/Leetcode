class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int prefixSum=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            prefixSum+=(nums[i]==0)?-1:1;
            if(mpp.find(prefixSum)!=mpp.end()){
                maxi=max(maxi,i-mpp[prefixSum]);
            }
           else mpp[prefixSum]=i;
        }
        return maxi;
    }
};