class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans[n - 1] = -1;
        for (int i = 0; i < n - 1; i++) {
            int x = arr[i];
            int maxVal = -1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > maxVal) {
                    maxVal = arr[j];
                }
                ans[i] = maxVal;
            }
        }
        return ans;
    }
};