class Solution {
public:
   bool sol(vector<int> &gas,vector<int>& cost,int start,int curr,int fuel){
        fuel+=gas[curr];
        fuel-=cost[curr];
        if(fuel<0)return false;
        int next=(curr+1)%gas.size();
        if(next==start)return true;
        return sol(gas,cost,start,next,fuel);
   }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int fuel=0;
        int total=0;
        int start=0;
        
        
        for(int i=0;i<n;i++){
            int gain=gas[i]-cost[i];
            total+=gain;
            fuel+=gain;
            if(fuel<0){
                start=i+1;
                fuel=0;
            }
        }
        // for(int i=0;i<gas.size();i++){
        //     if(sol(gas,cost,i,i,0))return i;
        // }
        // return -1;
        return total>=0?start:-1;
    }
};