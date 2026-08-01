class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++)mpp[s[i]]++;
        int j=0;
        unordered_map<char,int> mpp2;
        int ans=0;
        for(int i=0;i<n;i++){
            mpp2[s[i]]++;
            while(mpp2.size()==3){
                ans+=n-i;
                mpp2[s[j]]--;
                if(mpp2[s[j]]==0)mpp2.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};