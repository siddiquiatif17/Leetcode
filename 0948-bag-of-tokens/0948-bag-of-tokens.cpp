class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());

        int i=0;
        int j=n-1;
        int score=0;
        int ans=0;
        
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                ans=max(ans,score);
            }
           else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else {
                break;
            }
        }
        return ans;
    }
};