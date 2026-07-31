class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    set<int> st2;
    
    void sol(vector<int> &temp,vector<int>& nums){
        if(temp.size()==nums.size()){
            if(st.find(temp)==st.end()){
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(st2.find(i)==st2.end()){
                temp.push_back(nums[i]);
                st2.insert(i);
                sol(temp,nums);
                st2.erase(i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<int> temp;
            sol(temp,nums);
            return ans;
        
    }
};