class Solution {
public:

    int ans = INT_MAX;
    vector<vector<pair<int, int>>> adj;
    void dfs(int src, vector<bool>& vis) {
        vis[src] = true;

        for (auto [v, w] : adj[src]) {
            ans = min(ans, w);
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        adj.assign(n + 1, {});
        vector<bool> vis(n+1, false);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1, vis);
        
    return ans;
}
}
;