class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mpp;
        
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;
            while(mpp.size()>2){
                mpp[fruits[j]]--;
                if(mpp[fruits[j]]==0)mpp.erase(fruits[j]);
                j++;
            }
            ans=max(i-j+1,ans);
        }
        return ans;
        
    }
};