class Solution {
public:
    bool isPossible(vector<int>& nums,int k,int mid){
        int n=nums.size();
        int parts=1;
        int sum=0;
        for(int i=0;i<n;i++){
            
            if(sum+nums[i]>mid){
                parts++;
                sum=nums[i];
            }else sum+=nums[i];
        }
        return parts<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<n;i++)high+=nums[i];
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
        
    }
};