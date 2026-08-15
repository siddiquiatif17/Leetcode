class Solution {
public:
    string smallestSubsequence(string s) {
          int n=s.size();
       stack<char> st;
        vector<int> taken(26,0);
        vector<int> lastIndex(26,-1);
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if (taken[s[i]-'a']){
                continue;
            }
            while(!st.empty() && st.top()-'a'>s[i]-'a' && lastIndex[st.top()-'a']>i  ){
                taken[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            taken[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};