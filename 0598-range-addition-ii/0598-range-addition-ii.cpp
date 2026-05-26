class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow=m;
        int minCol=n;
        for(int i=0;i<ops.size();i++){
            int row=ops[i][0];
            int col=ops[i][1];
            minRow=min(minRow,row);
            minCol=min(minCol,col);
        }
        return minRow*minCol;
        
    }
};