class Solution {
public:
    int sol(int mid,vector<int>& nums){
        int count=0;
        int n=nums.size();
        int j=0;

        for(int i=0;i<n;i++){
            while(j<n && abs(nums[i]-nums[j])<=mid){
                j++;
            }
            count+=j-i-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int low=0;
        int high=nums[n-1]-nums[0];

        while(low<=high){
            int mid=low+(high-low)/2;
            if(sol(mid,nums)>=k)high=mid-1;
            
            else low=mid+1;
        }
        return low;
    }
};