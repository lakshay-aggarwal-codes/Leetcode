class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long dvd = dividend;
        long long dvs = divisor;
        bool neg = (dividend < 0) ^ (divisor < 0);
        dvd = abs(dvd);
        dvs = abs(dvs);
        long long ans = 0;
        long long rem = dvd;
        long long x = 0;
        while (rem >= dvs) {
            x = dvs;
            int i = 0;
            while ((x << 1) <= rem) {
                x <<= 1;
                i++;
            }
            rem -= x;
            ans += 1LL << (i);
        }
        if (neg)
            ans = -ans;
        return ans;
    }
};