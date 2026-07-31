class Solution {
public:
    vector<vector<int>> ans;

    void sol(vector<int>& nums,vector<int>&temp,int idx){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
            sol(nums,temp,idx+1);
            temp.push_back(nums[idx]);
            sol(nums,temp,idx+1);
            temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sol(nums,temp,0);
        return ans;
    }
};