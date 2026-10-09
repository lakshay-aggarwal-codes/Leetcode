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
    int dikjstra(vector<vector<int>>& times, int n, int k, int src, int V,
                 vector<vector<Edge>>& g) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(V + 1, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (cost > dist[u])
                continue;
            for (auto e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        int ans = 0;
        for (int i =1;i< dist.size();i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         
        int x = times.size();
        int V = n;
        int src = k;
        vector<vector<Edge>> g(n + 1);
        for (int i = 0; i < x; i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            g[u].push_back(Edge(v, wt));
        }
        int ans = dikjstra(times, n, k, src, V, g);
        if (ans == -1)
            return -1;
        return ans > 0 ? ans : 0;
    }
};