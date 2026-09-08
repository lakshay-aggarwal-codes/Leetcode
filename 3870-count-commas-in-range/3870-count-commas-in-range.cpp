class Solution {
public:
    int countCommas(int n) {
        int dig =0;
        int num = n;
        while(num >0){
            dig++;
            num/=10;
        }
        if (dig < 4)
            return 0;

        else
            return n - 999;
    }
};