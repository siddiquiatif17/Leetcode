class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++)mpp[t[i]]++;
        int count=m;
        int start=0;
        int mini=INT_MAX;     
        int j=0;
        for(int i=0;i<n;i++){
           if(mpp[s[i]]>0)count--;
           mpp[s[i]]--;
           while(count==0){
            if(i-j+1<mini){
                mini=i-j+1;
                start=j;
            }
            mpp[s[j]]++;
            if(mpp[s[j]]>0){
                count++;
            }
            j++;
           }
        }
        return (mini==INT_MAX)?"":s.substr(start,mini);
    }
};