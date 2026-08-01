class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int normal=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)normal+=customers[i];
        }       
        int j=0;
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==1){
            sum+=customers[i];
            }
            if(i-j+1==minutes){
                maxi=max(maxi,sum);
                if(grumpy[j]==1)
                sum-=customers[j];
                j++;
            }
            
        }
        return normal+maxi;
        
    }
};