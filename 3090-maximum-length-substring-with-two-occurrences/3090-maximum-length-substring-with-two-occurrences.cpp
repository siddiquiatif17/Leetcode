class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        // unordered_map<char,int> freq;
        vector<int> freq(26,0);
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            while(freq[s[i]-'a']>2){
                freq[s[j]-'a']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};