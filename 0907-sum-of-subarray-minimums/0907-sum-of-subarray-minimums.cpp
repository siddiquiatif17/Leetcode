class Solution {
public:
    int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())right[i]=n-1;
            else right[i]=st.top()-1;
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty())left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            long long leftRange=(i-left[i]+1)%MOD;
            long rightRange=(right[i]-i+1)%MOD;
            long long sum=(leftRange*rightRange*nums[i]);
            ans=(ans+sum)%MOD;
        }
        return ans;
    }
};