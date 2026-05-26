class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        int m=shifts.size();
        vector<int> diff(n,0);
        for(int i=0;i<m;i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int direction=shifts[i][2];
            if(direction==0){
                diff[start]-=1;
                if(end+1<n)diff[end+1]+=1;
            }
            else{
                diff[start]+=1;
                if(end+1<n)diff[end+1]-=1;
            }
        }
        for(int i=1;i<n;i++){
    diff[i] += diff[i-1];
}
        for(int i=0;i<n;i++){
           int curr=s[i]-'a';
            int shifted = ((curr + diff[i]) % 26 + 26) % 26;
            s[i] = shifted + 'a';
        }
        return s;
        
    }
};