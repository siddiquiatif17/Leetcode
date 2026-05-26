class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        vector<int> diff(n,0);
        for(int i=0;i<q;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diff[start]-=1;
            if(end+1<n)diff[end+1]+=1;
        }
        for(int i=1;i<n;i++){
         
          diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0)continue;
            if(nums[i]+diff[i]>0)return false;
        }
        return true;
    }
};