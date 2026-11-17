class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        if (n < 2 * k)
            return -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1; 
                int best = INT_MAX;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;
                    int change = 0;
                    for (int g = 0; g < d; g++) {
                        string x = "";
                        for (int t = 0; t < len / d; t++) {
                            x += s[i + g + t * d];
                        }
                        int st = 0;
                        int end = x.size() - 1;
                        while (st < end) {
                            if (x[st] != x[end]) {
                                change++;
                            }
                            st++;
                            end--;
                        }
                    }
                    best = min(best, change);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= k; p++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[j][p - 1] ==INT_MAX)
                        continue;
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};
