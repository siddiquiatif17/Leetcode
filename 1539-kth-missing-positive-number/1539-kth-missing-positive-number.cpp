class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mpp;
        int count=1;
        for(int i=0;i<n;i++)mpp[arr[i]]++;
        for(int i=1;i<arr[n-1]+k+1;i++){
            if(mpp.find(i)==mpp.end()){
                if(count==k)return i;
                count++;
            }
        }
        return -1;
        
    }
};