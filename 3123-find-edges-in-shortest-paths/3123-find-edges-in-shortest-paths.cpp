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
public:
    vector<long long> solve(int src, int V, vector<vector<Edge>>& g) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> dist(V, LLONG_MAX);
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] > d)
                continue;
            for (auto& e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<Edge>> g(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        vector<bool> ans(m, false);
        vector<long long> d1 = solve(0, n, g);
        vector<long long> d2 = solve(n - 1, n, g);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (d1[u] != LLONG_MAX && d2[u] != LLONG_MAX &&
                d1[v] != LLONG_MAX && d1[v] != LLONG_MAX) {
                if (d1[u] + w + d2[v] == d1[n - 1] ||
                    d1[v] + w + d2[u] == d1[n - 1]) {
                    ans[i] = true;
                }
            }
        }
        return ans;
    }
};