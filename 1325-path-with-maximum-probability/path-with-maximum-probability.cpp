class Edge {
public:
    int v;
    double wt;
    Edge(double v, double wt) {
        this->v = v;
        this->wt = wt;
    }
};
class Solution {
public:
    double solve(int src, int end, int V, vector<vector<Edge>>& g) {
        priority_queue<pair<double, int>> pq;
        vector<double> dist(V, 0.0);
        pq.push({1.0, src});
        dist[src] = 1.0;
        while (!pq.empty()) {

            int u = pq.top().second;
            double d = pq.top().first;
            pq.pop();
            if (d < dist[u])
                continue;
            if (u == end)
                return d;
            for (Edge e : g[u]) {
                if (dist[e.v] < dist[u] * e.wt) {
                    dist[e.v] = dist[u] * e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        return dist[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<Edge>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        int V = n;
        int src = start_node;
        int end = end_node;
        return solve(src, end, V, g);
    }
};