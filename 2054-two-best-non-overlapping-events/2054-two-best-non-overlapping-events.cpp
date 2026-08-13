class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        int n = events.size();
        sort(events.begin(), events.end(),
             [](const vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<int> prefMax(n);
        prefMax[0] = events[0][2];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], events[i][2]);
        }

        for (int i = 0; i < events.size(); i++) {
            int x = 0;
            int w = events[i][2];
            ans = max(w, ans);

            int target = events[i][0];
            int st = 0;
            int end = i - 1;
            int idx = -1;

            while (st <= end) {
                int mid = st + (end - st) / 2;
                if (events[mid][1] < target) {
                    idx = mid;
                    st = mid + 1;
                } else
                    end = mid - 1;
            }
            if (idx != -1)
                ans = max(ans, w + prefMax[idx]);
        }
        return ans;
    }
};