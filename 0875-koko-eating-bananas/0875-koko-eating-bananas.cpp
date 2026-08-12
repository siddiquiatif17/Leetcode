class Solution {
public: 
    bool possible(int k,vector<int>& piles,int h){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time+=(piles[i]%k==0)?piles[i]/k:(piles[i]/k)+1;
            if(time>h)return  false;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,piles,h)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};