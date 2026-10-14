class Solution {
public:
    void calc(int V, vector<int>& indeg, vector<vector<int>>& g) {
        for (int u = 0; u < V; u++) {
            for (int v : g[u]) {
                indeg[v]++;
            }
        }
    }
    int kahn(int V, vector<vector<int>>& g, string colors) {
        vector<int> indeg(V, 0);
        int nodes = 0;
        calc(V, indeg, g);
        queue<int> q;
        vector<vector<int>> dp(V, vector<int>(26, 0));
        for (int i = 0; i < V; i++) {
            for (int c = 0; c < 26; c++) {
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                nodes++;
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int v : g[curr]) {
                for (int c = 0; c < 26; c++) {
                    int z = 0;
                    if (colors[v] - 'a' == c) {
                        z = 1;
                    }
                    dp[v][c] = max(dp[v][c], dp[curr][c] + z);
                }

                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                    nodes++;
                }
            }
        }
        if (nodes < V) {
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < 26; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
        }
        return kahn(n, g, colors);
    }
};