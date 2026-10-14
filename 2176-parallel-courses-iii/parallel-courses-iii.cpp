class Solution {
public:
    void calcIndeg(vector<int>& indeg, int V, vector<vector<int>>& g) {
        for (int u = 0; u < V; u++) {
            for (int v : g[u]) {
                indeg[v]++;
            }
        }
    }
    int kahn(int V, vector<vector<int>>& g, vector<int>& time) {
        vector<int> indeg(V);
        vector<int> finish(V, 0);
        for (int i = 0; i < time.size(); i++) {
            finish[i+1] = time[i];
        }
        calcIndeg(indeg, V, g);
        queue<int> q;
        for (int i = 1; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int v : g[curr]) {
                indeg[v]--;
                finish[v] = max(finish[v], finish[curr] + time[v-1]);
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return *max_element(finish.begin(), finish.end());
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0];
            int v = relations[i][1];
            g[u].push_back(v);
        }
        int ans = kahn(n + 1, g, time);
        return ans > 0 ? ans : 0;
    }
};