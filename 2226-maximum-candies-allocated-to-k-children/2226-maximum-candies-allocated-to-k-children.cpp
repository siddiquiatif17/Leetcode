class Solution {
public:
    bool possible(int k,vector<int>& candies,long long children){
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count+=candies[i]/k;
            if(count>=children)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};