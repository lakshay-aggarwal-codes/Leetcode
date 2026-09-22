class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        int ans =INT_MIN;
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            vector<int> newdp(n + 1, INT_MIN);
            for (int x = 0; x <= i; x++) {
                int scoreLeft = nums[x] * multipliers[i];
                int scoreRight = nums[n - 1 - (i - x)] * multipliers[i];
                newdp[x + 1] = max(newdp[x + 1], dp[x] + scoreLeft);
                newdp[x] = max(newdp[x], dp[x] + scoreRight);
            }
            dp = newdp;
        }

        for (int i = 0; i <= m; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};