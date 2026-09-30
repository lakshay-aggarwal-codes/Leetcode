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
    void bfs(int n, Graph& g, vector<int>& ans) {
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            indeg[i] = g.l[i].size();
        }
        queue<int> q;
        int rem = n;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1) {
                q.push(i);
            }
        }

        while (rem > 2) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                for (int v : g.l[curr]) {
                    indeg[v]--;
                    if (indeg[v] == 1) {
                        q.push(v);
                    }
                }
            }
            rem -= size;
        }

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        Graph g(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g.addEdge(u, v);
        }
        vector<int> ans;
        bfs(n, g, ans);
        return ans;
    }
};