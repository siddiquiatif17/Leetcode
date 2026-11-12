class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int maxi2=0;
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                maxi=max(maxi,i-j);
                j=i;
            }
        }
        maxi=max(maxi,n-j);
        j=0;
         for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                maxi2=max(maxi2,i-j);
                j=i;
            }
        }
        maxi2=max(maxi2,n-j);
        return max(maxi,maxi2);
        
    }
};