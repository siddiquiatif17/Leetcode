class Solution {
public:
    int MOD=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixSum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
        vector<int> right(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())right[i]=n-1;
          else right[i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty())st.pop();

        vector<int> left(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
           long long minProduct=((prefixSum[right[i]+1]-prefixSum[left[i]]))*nums[i];
           ans=max(ans,minProduct);
        }
        return ans%MOD;
        
    }
};