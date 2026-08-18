class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int val = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            val = max(val, arr[i]);
            if (i == val) {
                ans++;
            }
        }
        return ans;
    }
};