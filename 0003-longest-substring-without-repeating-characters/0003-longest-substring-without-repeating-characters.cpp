class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int j=0;
        int len=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.count(s[i])){
                // maxi=max(maxi,i-j+1);
                j=max(j,mpp[s[i]]+1);
            }
            mpp[s[i]]=i;
            len=max(len,i-j+1);

        }

        return len;
    }
};