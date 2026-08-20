class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> car;
        for (int i = 0; i < n; i++) {
            double time =(double)(target - position[i]) / speed[i];
            car.push_back({position[i], time});
        }
        sort(car.rbegin(), car.rend());
        int ans = 0;
        double maxTime = 0;

        for (auto& c : car) {
            double time = c.second;
             if (time > maxTime) {
                ans++;
                maxTime = time;
            }
        }
        return ans;
    }
};