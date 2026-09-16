class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        set<int>st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int maxi=1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x=it;
                int count=1;
                while(st.find(x+1)!=st.end()){
                    x++;
                    count++;
                }
                maxi=max(maxi,count);
                
            }
        }
        return maxi;
    }
};