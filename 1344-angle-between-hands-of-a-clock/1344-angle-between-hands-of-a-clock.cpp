class Solution {
public:
    double angleClock(int hour, int minutes) {
        int hourRem=hour%12;
        double diff1=(minutes*6)-(hourRem*30);
        double ans=abs(diff1-(double)minutes/2);
        double mini=min(ans,360-ans);
        
        return mini;
        
    }
};