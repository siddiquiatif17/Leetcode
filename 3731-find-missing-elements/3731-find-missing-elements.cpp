class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int end=nums[n-1];
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++)mpp[nums[i]]++;
        for(int i=start;i<=end;i++){
            if(mpp.find(i)==mpp.end())ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};