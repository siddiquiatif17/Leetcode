class Solution {
public:
    vector<int> rightMax(vector<int>& height){
        int n=height.size();
        vector<int> rightMax(n,0);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    vector<int> leftMax(vector<int>& height){
        int n=height.size();
        vector<int> leftMax(n,0);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left=leftMax(height);
        vector<int> right=rightMax(height);
        int water=0;
        for(int i=0;i<n;i++){
           
            int trap=min(left[i],right[i])-height[i];
            water+=trap;
        }
    return water;
        
    }
};