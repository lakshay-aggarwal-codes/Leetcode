class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        int n = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0;
        int dist = 0;
        int j = 0;
        while (i < houses.size()) {
            while (j + 1 < heaters.size()) {
                int x = abs(houses[i] - heaters[j]);
                int y = abs(houses[i] - heaters[j + 1]);

                if (y <= x) {
                    j++;
                } else
                    break;
            }
            dist = abs(houses[i]- heaters[j]);

            ans = max(ans, dist);
            i++;
        }

        return ans;
    }
};