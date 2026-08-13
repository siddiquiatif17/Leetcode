class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        return temp[k-1];
        
    }
};