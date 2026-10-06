class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int i = 0;
        while (i < n) {
            ans += (i / 7) + (i % 7) + 1;
            i++;
        }
        return ans;
    }
};