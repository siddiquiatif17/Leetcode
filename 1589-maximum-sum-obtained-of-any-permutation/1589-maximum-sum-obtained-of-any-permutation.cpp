class Solution {
public:
    int MOD=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        int req=requests.size();
       
        sort(nums.begin(),nums.end());

        vector<int> diff(n,0);
        for(int i=0;i<req;i++){
            diff[requests[i][0]]++;
            if(requests[i][1]+1<n)diff[requests[i][1]+1]--;
        }
        for(int i=1;i<n;i++)diff[i]+=diff[i-1];
        priority_queue<int> pq;
        for(int i=0;i<n;i++)pq.push(diff[i]);
        int k=n-1;
        long long sum=0;
        while(!pq.empty()){
           
             sum=(sum+1LL*pq.top()*nums[k])%MOD;
            pq.pop();
            k--;
        } 
        return (int)sum;
        
    }
};