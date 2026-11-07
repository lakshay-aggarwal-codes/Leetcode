class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busy;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            avl;
        for (int i = 0; i < n; i++) {
            avl.push({servers[i], i});
        }
        long long currTime = 0;
        for (int j = 0; j < m; j++) {
            currTime = max(currTime, (long long)(j));
            while (!busy.empty() && get<0>(busy.top()) <= currTime) {
                int wt = get<1>(busy.top());
                int idx = get<2>(busy.top());
                avl.push({wt, idx});
                busy.pop();
            }

            if (avl.empty()) {

                currTime = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= currTime) {

                    int wt = get<1>(busy.top());
                    int idx = get<2>(busy.top());

                    avl.push({wt, idx});
                    busy.pop();
                }
            }

            ans[j] = avl.top().second;
            busy.push({currTime + tasks[j], avl.top().first, avl.top().second});
            avl.pop();
        }
        return ans;
    }
};