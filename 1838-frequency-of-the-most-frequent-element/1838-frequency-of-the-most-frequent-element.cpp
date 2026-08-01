class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long sum=0;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            // long long required=(i-j+1)*nums[i];
            sum+=nums[i];
            long long available=sum+k;
            while(available<1LL*(i-j+1)*nums[i]){
                sum-=nums[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans; 
    }
};