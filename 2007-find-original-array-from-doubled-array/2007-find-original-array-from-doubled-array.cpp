class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0)return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++)mpp[nums[i]]++;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]==0)continue;
            if(mpp[2*nums[i]]==0)return {};
            ans.push_back(nums[i]);
            mpp[nums[i]]--;
            mpp[nums[i]*2]--;
        }
        return ans;
    }
};