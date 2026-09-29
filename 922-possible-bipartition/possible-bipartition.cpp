class Graph {
public:
    int V;
    list<int>* l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
};

class Solution {
public:
    bool solve(int n, Graph& g) {
        queue<int> q;
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int v : g.l[curr]) {
                        if (color[v] == -1) {
                            color[v] = !color[curr];
                            q.push(v);
                        }
                        else {
                            if (color[v] == color[curr]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        Graph g(n);

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            g.addEdge(u, v);
        }

        return solve(n, g);
    }
};