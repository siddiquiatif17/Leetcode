class Solution {
public:
    bool possible(int k,vector<int>& nums,int maxOperations){
        int count=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
          count+=(nums[i]-1)/k;
          if(count>maxOperations)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
      

        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,maxOperations)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return ans;
        
    }
};