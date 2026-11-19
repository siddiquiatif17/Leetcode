class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n=nums.size();
       
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=nums[i];
             int bitwise=nums[i];
            for(int j=i;j<n;j++){
              mini = min(mini, nums[j]);
                bitwise = bitwise & nums[j];

                if(bitwise == mini) {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};