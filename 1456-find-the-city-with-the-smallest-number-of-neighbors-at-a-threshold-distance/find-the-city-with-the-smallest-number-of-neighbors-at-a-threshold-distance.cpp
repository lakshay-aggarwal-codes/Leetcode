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
    int solve(int src, int distanceThreshold, int V, vector<vector<Edge>>& g) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
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
        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (i != src) {
                if (dist[i] <= distanceThreshold) {
                    ans++;
                }
            }
        }
        return ans;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<Edge>> g(n);
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        } 
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = solve(i, distanceThreshold, n, g);
        }
        int z = INT_MAX;
        for (int i = 0; i < n; i++) {
            z = min(z, c[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (c[i] == z) {
                return i;
            }
        }
        return -1;
    }
};