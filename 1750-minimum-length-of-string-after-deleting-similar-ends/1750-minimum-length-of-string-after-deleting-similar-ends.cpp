class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int j=n-1;
        int i=0;

        while(i<j){
            char prefix=s[i];
            char suffix=s[j];
            if(prefix!=suffix)break;
                
        while(i<=j && s[i]==prefix)i++;
        while(i<=j && s[j]==suffix)j--;
       
            
           
        }
        return j-i+1;
        
    }
};