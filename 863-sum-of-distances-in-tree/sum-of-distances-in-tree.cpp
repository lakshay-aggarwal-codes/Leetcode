class Graph {
public:
    int V;
    list<int>* l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
};
class Solution {
public:
    void dfs(int src, vector<bool>& vis, vector<int>& subtree, vector<int>& ans,
             Graph& g) {
        vis[src] = true;
        subtree[src] = 1;

        for (int v : g.l[src]) {
            if (!vis[v]) {
                dfs(v, vis, subtree, ans, g);
                subtree[src] += subtree[v];
                ans[src] += subtree[v] + ans[v];
            }
        }
        vis[src] = false;
    }

    void solve(int n, Graph& g, int src, vector<int>& subtree, vector<int>& ans,
               int parent) {
        for (int v : g.l[src]) {
            if (v == parent)
                continue;
            ans[v] = ans[src] + n - 2 * subtree[v];
            solve(n, g, v, subtree, ans, src);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        Graph g(n);
        vector<int> subtree(n, 0);
        vector<bool> vis(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g.addEdge(u, v);
        }
        vector<int> ans(n, 0);
        dfs(0, vis, subtree, ans, g);
        solve(n, g, 0, subtree, ans, -1);
        return ans;
    }
};