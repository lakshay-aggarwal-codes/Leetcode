
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;

        for (int x : nums) {
            string ans = "";
            while (x >= (1 << 25)) {
                ans += 'z';
                x -= (1 << 25);
            }
            for (int i = 24; i >= 0; i--) {
                int maxPower = 1 << i;

                if (x >= maxPower) {
                    ans += char('a' + i);
                    x -= maxPower;
                }
            }
            res.push_back(ans);
        }

        return res;
    }
};
