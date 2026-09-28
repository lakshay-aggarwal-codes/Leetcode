class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (long long factor = 1; factor <= n; factor *= 10) {
            long long higher = n / (factor * 10);
            long long current = (n / factor) % 10;
            long long lower = n % factor;
            if (current < 1) {
                ans += higher * factor;
            } else if (current == 1) {
                ans += higher * factor + lower + 1;
            } else {
                ans += (higher + 1) * factor;
            }
        }
        return ans;
    }
};