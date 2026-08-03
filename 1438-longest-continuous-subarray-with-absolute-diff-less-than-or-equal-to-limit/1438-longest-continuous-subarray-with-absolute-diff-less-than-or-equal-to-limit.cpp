class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> maxDq;
        deque<int> minDq;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(!maxDq.empty() && maxDq.back()<nums[i])maxDq.pop_back();
            maxDq.push_back(nums[i]);
            while(!minDq.empty() && minDq.back()>nums[i])minDq.pop_back();
            minDq.push_back(nums[i]);
            while(maxDq.front()-minDq.front()>limit){
                if(nums[j]==maxDq.front())maxDq.pop_front();
                if(nums[j]==minDq.front())minDq.pop_front();
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};