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
    int solve(int src, int V, vector<vector<Edge>>& g, vector<int>& passingFees,
              int maxTime) {
        int n = passingFees.size();
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));
        dp[0][0] = passingFees[0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({passingFees[src], src, 0});
        while (!pq.empty()) {
            auto [cost, node, time] = pq.top();
            pq.pop();
            if (cost != dp[node][time])
                continue;
            for (auto& e : g[node]) {
                int nextTime = time + e.wt;
                int nextCost = cost + passingFees[e.v];
                if (nextTime > maxTime)
                    continue;
                if (nextCost < dp[e.v][nextTime]) {
                    dp[e.v][nextTime] = nextCost;
                    pq.push({nextCost, e.v, nextTime});
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= maxTime; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }

public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<Edge>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        int ans = solve(0, n, g, passingFees, maxTime);
        return ans == INT_MAX ? -1 : ans;
    }
};