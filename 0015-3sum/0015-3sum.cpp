class Solution {
public:
vector<vector<int>> result;
    void  twoSum(vector<int> &nums,int i,int target){
        int n=nums.size();
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                result.push_back({-target,nums[i],nums[j]});
                int a=nums[i];
                int b=nums[j];
                while(i<n && nums[i]==a)i++;
                while(j>0 && nums[j]==b)j--;
            }

            else if(nums[i]+nums[j]>target)j--;
            else i++;
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int target=-nums[i];
            twoSum(nums,i+1,target);
        }

        return result;
    }
};