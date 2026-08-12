class Solution {
public:
    bool possible(int k,vector<int>& position,int m){
        int count=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=k){
                count++;
                last=position[i];
            }
            if(count==m)return true;
        }
        return false;   
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());

        int low=1;
        int high=position.back()-position.front();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,position,m)){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};