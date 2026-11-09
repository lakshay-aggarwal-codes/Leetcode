class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        int n = arrival.size();
        vector<int> server(k, 0);
        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                int x = pq.top().second;
                pq.pop();
                st.insert(x);
            }

            if (st.empty()) {
                continue;
            }

            auto it = st.lower_bound(i % k);

            if (it == st.end()) {
                it = st.begin();
            }

            int id = *it;
            st.erase(it);

            pq.push({arrival[i] + load[i], id});
            server[id]++;
        }

        int mx = *max_element(server.begin(), server.end());

        for (int i = 0; i < k; i++) {
            if (server[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};