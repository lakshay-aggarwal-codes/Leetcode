class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int sum = 0;
        int ans = 0;
        int score = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = satisfaction[i];
            if (x + sum >= 0) {
                sum += x;
                score += sum;
                ans = max(ans, score);
            } else
                break;
        }
        return ans;
    }
};