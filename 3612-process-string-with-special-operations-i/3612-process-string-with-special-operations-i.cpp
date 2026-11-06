class Solution {
public:
    void pushArr(char ch,string & ans){
        if(ch=='#')ans+=ans;
        else if(ch=='*' && !ans.empty())ans.pop_back();
        else reverse(ans.begin(),ans.end());
    }
    string processStr(string s) {
        int  n=s.size();
        
        string ans="";
        for(int i=0;i<n;i++){
          
         if(s[i]!='*' && s[i]!='#' && s[i]!='%')
            ans+=s[i];

        else pushArr(s[i],ans);
        }

        return ans;
    }
};