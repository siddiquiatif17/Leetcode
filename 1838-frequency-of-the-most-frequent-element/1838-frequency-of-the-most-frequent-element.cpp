class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long sum=0;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum+k<1LL*(i-j+1)*nums[i]){
                sum-=nums[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans; 
    }
};