class Solution {
public:
    const int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int> dp(n + 1, -1);
        if (n <= 2)
            return n;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};