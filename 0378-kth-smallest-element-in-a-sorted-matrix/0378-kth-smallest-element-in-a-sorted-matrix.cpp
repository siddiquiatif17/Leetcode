class Solution {
public:
    int sol(int m,vector<vector<int>>& matrix){
        int count=0;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=m)count++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];

        while(low<=high){
            int mid=low+(high-low)/2;
            if(sol(mid,matrix)>=k){
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return low;
    }
};