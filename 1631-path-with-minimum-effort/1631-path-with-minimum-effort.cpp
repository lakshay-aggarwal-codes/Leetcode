class Solution {
public:
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
    priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;
            int newCost = 0;

            if(effort> dist[r][c]) continue;
            if(r== n-1 && c==m-1) return effort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int edgeCost = abs(heights[r][c] - heights[nr][nc]);
                    newCost = max(dist[r][c], edgeCost);

                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};