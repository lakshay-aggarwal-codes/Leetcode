class Solution {
public:
    const int mod = 1e9 + 7;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> newdp(target + 1, 0);
            int count = types[i][0];
            int points = types[i][1];
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= count; k++) {
                    int newScore = j + k * points;
                    if (newScore <= target)
                        newdp[newScore] = (1LL * newdp[newScore] + dp[j]) % mod;
                }
            }
            dp = newdp;
        }

        return dp[target];
    }
};