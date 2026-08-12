class Solution {
public:
    bool possible(int k,vector<int>& weights,int days){
        int time=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=k){
                sum+=weights[i];
            }else{
                sum=weights[i];
                time++;
            }
        }
        return time<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++)high+=weights[i];
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans; 
    }
};