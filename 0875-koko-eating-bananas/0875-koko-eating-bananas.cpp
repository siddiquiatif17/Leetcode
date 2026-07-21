class Solution {
public:
    bool canEat(vector<int>& nums,int h,int k){
        int n=nums.size();
        int hour=0;
        for(int i=0;i<n;i++){
            hour+=(nums[i]%k==0)?nums[i]/k:nums[i]/k+1;
            if(hour>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<n;i++)high=max(high,piles[i]);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canEat(piles,h,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};