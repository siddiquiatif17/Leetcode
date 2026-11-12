class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long prev=nums[n-1];

        for(int i=n-2;i>=0;i--){
            if(nums[i]<=prev){
                prev=nums[i];
            }else{
                long long parts=(nums[i]+prev-1)/prev;
                ans+=parts-1;
            if(parts>0)    prev=nums[i]/parts;
            }
        }
        return ans;
    }
};