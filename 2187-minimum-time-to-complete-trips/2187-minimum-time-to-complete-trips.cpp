class Solution {
public: 
    bool possible(long long k,vector<int>& time,int totalTrips){
        long long count=0;
        for(int i=0;i<time.size();i++){
            count+=k/time[i];
            if(count>=totalTrips)return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        // sort(time.begin(),time.end());
        long long low=1;
        long long mini=*min_element(time.begin(),time.end());
        long long high=1LL*mini*totalTrips;
        long long ans=INT_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(mid,time,totalTrips)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;    
        }
        return ans;
        
    }
};