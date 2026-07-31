class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0 )return false;
       map<int,int> mpp;
       for(int i=0;i<n;i++)mpp[hand[i]]++;

       while(!mpp.empty()){
        int start=mpp.begin()->first;
        for(int i=0;i<groupSize;i++){
            int card=start+i;
            if(mpp.find(card)==mpp.end()){
                return false;
            }
            mpp[card]--;
            if(mpp[card]==0)mpp.erase(card);
        }
       }
        return true;
    }
};