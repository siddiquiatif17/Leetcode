class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=INT_MIN;
        int i=0;
        int j=n-1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         maxi=max((j-i)*min(height[i],height[j]),maxi);
        //     }
        // }
        while(i<j){
            maxi=max((j-i)*min(height[i],height[j]),maxi);
            if(height[i]>=height[j]){
                j--;
            }else i++;
        }
        return maxi;
        
    }
};