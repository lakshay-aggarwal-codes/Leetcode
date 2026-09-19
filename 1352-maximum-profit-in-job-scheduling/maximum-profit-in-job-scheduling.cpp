class Solution {
public:
    struct Job {
        int start;
        int end;
        int profit;
    };
    int solve(vector<Job>& jobs, vector<int>& dp) {
        int n = jobs.size();
        for (int i = 0 ; i < n; i++) {
            int skip = dp[i];
            int st = 0;
            int end = i - 1;
            int j = -1;
            while (st <= end) {
                int mid = st + (end - st) / 2;
                if (jobs[mid].end <= jobs[i].start) {
                    j = mid;
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            int take = jobs[i].profit + dp[j + 1];
            dp[i+1] = max(skip, take);
        }
        return dp[n];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        int n = profit.size();
        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(),
             [](Job a, Job b) { return a.end < b.end; }); 

        vector<int> dp(n + 1);
        dp[0] = 0;
        int ans = solve(jobs, dp);
        return ans;
    }
};