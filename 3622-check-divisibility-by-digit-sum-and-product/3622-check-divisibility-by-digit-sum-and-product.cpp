class Solution {
public:
    bool checkDivisibility(int n) {
        int digitProduct=1;
        int sum=0;
        int originalNumber=n;

        while(n>0){
            int rem=n%10;
            digitProduct*=rem;
            sum+=rem;
            n/=10;
        }
        return (originalNumber%(digitProduct+sum)==0)?true:false;
        
    }
};