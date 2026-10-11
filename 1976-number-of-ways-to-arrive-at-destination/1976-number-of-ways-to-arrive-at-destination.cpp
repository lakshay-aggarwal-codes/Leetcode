class Edge {
public:
    int v;
    int wt;
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};
const int mod = 1e9 + 7;
class Solution {
    int solve(int src, int V, vector<vector<Edge>>& g) {
        vector<long long> dist(V, LLONG_MAX);
        vector<long long> ways(V, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if (dist[u] < d)
                continue;
            for (auto e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v], e.v});
                    ways[e.v] = ways[u];
                } else if (dist[e.v] == dist[u] + e.wt) { 
                    ways[e.v] = (ways[e.v] + ways[u]) % mod;
                }
            }
        }
        return ways[V - 1];
        ;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        vector<vector<Edge>> g(n);
        int V = n;
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        int ans = 0;
        ans = solve(src, V, g);
        return ans;
    }
};