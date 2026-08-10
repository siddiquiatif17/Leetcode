class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=n-1;
        int j=0;
        int boats=0;
        while(i>=j){
            if(people[i]+people[j]<=limit){
                boats++;
                i--;
                j++;
            }
            else {
                boats++;
                i--;
            }
        }
        return boats;
        
    }
};