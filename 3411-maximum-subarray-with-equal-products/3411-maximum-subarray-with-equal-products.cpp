class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b > 0) {
            long long rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long l = 1;
            long long g = 0;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);

                if (prod > l * g) break;

                if (prod == l * g) {
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};