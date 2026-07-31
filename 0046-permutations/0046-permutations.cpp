class Solution {
public:
    vector<vector<int>> ans;
    void sol(vector<int> &temp,vector<int> &nums,set<int> &st){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                sol(temp,nums,st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
       set<int> st;
        sol(temp,nums,st);
        return ans;
    }
};