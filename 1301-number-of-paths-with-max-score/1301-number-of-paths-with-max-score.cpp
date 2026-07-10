class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(
            n + 1, vector<pair<int, int>>(n + 1, {-1, 0}));

        dp[n - 1][n - 1] = {0, 1};
      
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'S')
                    continue;
                if (board[i][j] == 'X')
                    continue;

                auto down = dp[i + 1][j];
                auto right = dp[i][j + 1];
                auto diag = dp[i + 1][j + 1];

                int best = max({down.first, right.first, diag.first});

                if (best == -1)
                    continue;
                int ways = 0;
                if (down.first == best)
                   ways = (ways + down.second)%mod;
                if (right.first == best)
                   ways = (ways + right.second)%mod;
                if (diag.first == best)
                    ways = (ways + diag.second)%mod;

                dp[i][j].second = ways % mod;
                if (board[i][j] == 'S' || board[i][j] == 'E') {
                    dp[i][j].first = best;
                } else
                    dp[i][j].first = best + (board[i][j] - '0');
            }
        }
        if (dp[0][0].second == 0)
            return {0, 0};
        else
            return {dp[0][0].first, dp[0][0].second}    ;
    }
};