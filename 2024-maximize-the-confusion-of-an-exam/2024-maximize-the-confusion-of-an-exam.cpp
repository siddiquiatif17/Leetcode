class Solution {
public:
    int sol(string s,int k,char ch){
        int n=s.size();
        int j=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch)cnt++;
            while(cnt>k){
                if(s[j]==ch)cnt--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(sol(answerKey,k,'F'),sol(answerKey,k,'T'));
    }
};