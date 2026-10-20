class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(target+1, false));

        for (int i = 0; i < n; i++) {
            int node = i;
            int mask = 1 << i;
            int dist = 0;
            q.push({node, mask, dist});
            vis[node][mask] = true;
        }

        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == target) {
                return dist;
            }
            for (auto v : graph[u]) {
                int newMask = mask | (1 << v);
                if (!vis[v][newMask]) {
                    vis[v][newMask] = true;
                    q.push({v, newMask, dist + 1});
                }
            }
        }
        return -1;
    }
};