class Solution {
public:
    int reverse(int x) {
        long long num = abs((long long)x);
        long long ans = 0;
        while (num > 0) {
            int lastDig = num % 10;
            ans = ans * 10 + lastDig;
            num /= 10;
        }
        if (x < 0) {
            if (ans <= 2147483648)
                return -ans;
        } else if (ans <= 2147483647)
            return ans;

            return 0;
    }
};