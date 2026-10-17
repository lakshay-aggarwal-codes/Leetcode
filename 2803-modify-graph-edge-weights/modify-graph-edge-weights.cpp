class Edge {
public:
    int v;
    int wt;
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};
class Solution {
    long long solve(int src, int V, int dest, vector<vector<int>>& edges) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        int x = edges.size();
        vector<vector<Edge>> g(V);
        for (int i = 0; i < x; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        vector<long long> dist(V, LLONG_MAX);
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] > d)
                continue;
            for (const auto& e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        return dist[dest];
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        long long maxwt = 2 * 1000000000;
        int s = edges.size();
        vector<bool> vis(edges.size(), false);
        for (int i = 0; i < s; i++) {
            if (edges[i][2] < 0) {
                vis[i] = true;
                edges[i][2] = maxwt;
            }
        }

        long long d = solve(source, n, destination, edges);
        if (d < target) {
            return {};
        } else if (d == target) {
            return edges;
        } else {
            for (int i = 0; i < s; i++) {
                if (!vis[i])
                    continue;
                edges[i][2] = 1;

                long long d = solve(source, n, destination, edges);
                if (d <= target) {
                    edges[i][2] += (target - d);
                    return edges;
                }
            }
            return {};
        }
        return {};
    }
};