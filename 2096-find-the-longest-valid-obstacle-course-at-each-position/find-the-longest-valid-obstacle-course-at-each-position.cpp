class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
         int n = obstacles.size();

        vector<int> tails;
        vector<int> ans;

        for (int x : obstacles) {
            auto it = upper_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
                ans.push_back(tails.size());
            } else {
                int len = distance(tails.begin(), it) + 1;
                *it = x;
                ans.push_back(len);
            }
        }
        return ans;
    }
};
