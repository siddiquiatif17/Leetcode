class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        int cnt2=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]<target)cnt++;
            else if(nums[i]==target)cnt2++;
        }
        for(int i=cnt;i<cnt+cnt2;i++)ans.push_back(i);
        return ans;
        
    }
};