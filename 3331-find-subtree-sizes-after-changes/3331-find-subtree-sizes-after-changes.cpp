class Solution {
public:
    void solve(string& s, vector<vector<int>>& adj, vector<int>& parent,
               vector<int>& newParent, vector<int>& last, int node) {
        int ch = s[node] - 'a';
        int prev = last[ch];
        if (prev == -1) {
            newParent[node] = parent[node];
        } else {
            newParent[node] = prev;
        }

        last[ch] = node;

        for (auto child : adj[node]) {
            solve(s, adj, parent, newParent, last, child);
        }
        last[ch] = prev;
    }

   
    int sizeSub(vector<vector<int>>& adj2, int node,  vector<int>& ans) {
        int size = 1;
        for (auto child : adj2[node]) {
            size += sizeSub(adj2, child, ans);
        }
        ans[node] = size;
        return size;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> adj2(n);
        vector<int> newParent(n, -1);
        vector<int> last(26, -1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        solve(s, adj, parent, newParent, last, 0);
        for (int i = 1; i < n; i++) {
            adj2[newParent[i]].push_back(i);
        }
        vector<int> ans(n);
        sizeSub(adj2, 0, ans);
        return ans;
    }
};