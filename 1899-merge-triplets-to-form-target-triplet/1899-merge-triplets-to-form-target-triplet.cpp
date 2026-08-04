class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<int> maximum(3,0);
        for(int i=0;i<n;i++){
            int a=triplets[i][0];
            int b=triplets[i][1];
            int c=triplets[i][2];
            if(a>target[0] || b>target[1] || c>target[2])continue;
           maximum[0]=max(a,maximum[0]);
           maximum[1]=max(b,maximum[1]);
           maximum[2]=max(c,maximum[2]);
            if(maximum==target)return true;
        }
        return false;
    }
};