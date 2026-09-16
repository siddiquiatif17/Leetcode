class Solution {
public:
    bool isPossible(vector<int>& piles,int k,int h){
        int count=0;
        for(int i=0;i<piles.size();i++){
            count+=(piles[i]%k==0)?piles[i]/k:(piles[i]/k)+1;
            if(count>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};