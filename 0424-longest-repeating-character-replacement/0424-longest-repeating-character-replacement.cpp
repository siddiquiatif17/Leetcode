class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26,0);
        int j=0;
        int ans=0;
        int max_freq=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'A']++;
            max_freq=*max_element(freq.begin(),freq.end());
            while((i-j+1)-max_freq>k){
                freq[s[j]-'A']--;
                j++;
                max_freq=*max_element(freq.begin(),freq.end());
            }
            ans=max(ans,i-j+1);
        }
        return ans;
        
    }
};