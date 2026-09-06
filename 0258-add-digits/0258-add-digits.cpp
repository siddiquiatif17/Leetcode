class Solution {
public:
    int sol(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>9){
            num=sol(num);
        }
        return num;
        
    }
};