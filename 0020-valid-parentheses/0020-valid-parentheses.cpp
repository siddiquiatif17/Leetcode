class Solution {
public:
    bool isValid(string s) {
        int n=s.size();

        stack<char> st;
        for(int i=0;i<n;i++){
            // if(s[i]=='(' || s[i]=='{' ||  s[i]=='[')st.push(s[i]);
            char ch=s[i];
            if((s[i]==')' || s[i]=='}' || s[i]==']')  ){
                if(st.empty() || ((s[i]==')' && st.top()!='(')||( s[i]=='}' && st.top()!='{')||(s[i]==']' && st.top()!='[')))return false;
            }

            if((s[i]==')' || s[i]=='}' || s[i]==']')  ){
                if(((s[i]==')' && st.top()=='(')||( s[i]=='}' && st.top()=='{')||(s[i]==']' && st.top()=='['))){
                    st.pop();
                    continue;
                }
            }
            
            st.push(s[i]);
        }
        if(st.empty())return true;
        return false;
    }
};