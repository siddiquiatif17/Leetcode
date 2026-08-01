class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
     
        int j=0;
        // unordered_map<char,int> mpp2;
        int cnt[3]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            // mpp2[s[i]]++;
            cnt[s[i]-'a']++;
            while(cnt[0] && cnt[1] && cnt[2]){
                ans+=n-i;
                // mpp2[s[j]]--;
                cnt[s[j]-'a']--;
                // if(mpp2[s[j]]==0)mpp2.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};