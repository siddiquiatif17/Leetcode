class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int cnt=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt--;
            while(cnt<0){
                if(nums[j]==0)cnt++;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans-1;
    }
};