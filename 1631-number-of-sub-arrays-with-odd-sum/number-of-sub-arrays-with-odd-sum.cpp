class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int odd = 0;
        int even = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + arr[i]) % mod;
            if (sum % 2 != 0) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }
        return ans;
    }
};