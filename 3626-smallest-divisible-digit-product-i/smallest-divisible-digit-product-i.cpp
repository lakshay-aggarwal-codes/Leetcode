class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = 1;
            int num = n;
            while (num > 0) {
                int dig = num % 10;
                x *= dig;
                num /= 10;
            }
            if (x % t == 0)
                return n;
            n++;
        }
        return -1;
    }
};