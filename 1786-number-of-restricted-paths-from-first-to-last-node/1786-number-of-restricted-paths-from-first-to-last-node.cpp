class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int src, int n, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (cost > dist[u])
                continue;
            for (auto [v, wt] : adj[u]) {
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> order(n);
        for (int i = 1; i <= n; i++) {
            order[i - 1] = i;
        }
        sort(order.begin(), order.end(),
             [&](int a, int b) { return dist[a] < dist[b]; });

        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        for (int i : order) {
            for (auto [v, wt] : adj[i]) {
                if (dist[i] > dist[v]) {
                    dp[i] = (dp[i] + dp[v]) % mod;
                }
            }
        }
        return dp[1];
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        return solve(n, n, adj);
    }
};