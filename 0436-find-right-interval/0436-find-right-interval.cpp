class Solution {
public:
    int sol(vector<vector<int>>& intervals,int val,unordered_map<int,int>& mpp){
        int low=0;
        int high=intervals.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]>=val){
                ans=mpp[intervals[mid][0]];
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)mpp[intervals[i][0]]=i;
        sort(intervals.begin(),intervals.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int originalIndex=mpp[intervals[i][0]];
            ans[originalIndex]=sol(intervals,intervals[i][1],mpp);
        }
        return ans;
        
    }
};