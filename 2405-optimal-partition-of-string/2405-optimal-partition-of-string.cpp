class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        set<char> st;
        int ans=1;
        for(int i=0;i<n;i++){
            if(st.count(s[i])){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans;

        
     
        
    }
};