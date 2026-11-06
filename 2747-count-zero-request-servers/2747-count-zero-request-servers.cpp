class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);

        // for (int i = 0; i < m; i++) {
        //     int t1 = queries[i] - x;
        //     int t2 = queries[i];
        //     unordered_set<int> s;
        //     for (int j = 0; j < logs.size(); j++) {
        //         int y = logs[j][1];
        //         if (y >= t1 && y <= t2) {
        //            s.insert(logs[j][0]);
        //         }
        //     }
        //     ans[i] = n - s.size();
        // }

        vector<int> freq(n + 1, 0);
        int left = 0;
        int right = 0;
        vector<pair<int, int>> query;
        int server = 0;

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        for (int i = 0; i < m; i++) {
            query.push_back({queries[i], i});
        }
        sort(query.begin(), query.end());

        for (int i = 0; i < query.size(); i++) {
            auto [q, idx] = query[i];
           
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right][0];

                if (freq[id] == 0) {
                    server++;
                }
                freq[id]++;
                right++;
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];

                freq[id]--;
                if (freq[id] == 0) {
                    server--;
                }
                left++;
            }
            ans[idx] = n - server;
        }
        return ans;
    }
};