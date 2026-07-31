class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int i=n-1;
        int j=n-1;
        int count=0;
        sort(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums2[i],i});
        }

        
        vector<int> ans(n);
       
        int left=0;
        int right=n-1;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int val=temp.first;
            int idx=temp.second;
            if(nums1[right]>val){
                ans[idx]=nums1[right];
                right--;
            }else{
                ans[idx]=nums1[left];
                left++;
            }
        }
        return ans;
        
    }
};