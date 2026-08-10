class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                ans++;
                i++;
                j--;
            }
            else if(nums[j]+nums[i]>k){
                j--;
            }else i++;
        }
        return ans; 
    }
};