class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        stack<int> st;
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            } else
                left[i] = st.top();

            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n;
            } else
                right[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int prev = i - left[i];
            int next = right[i] - i;
            sum = (sum + 1LL*arr[i] * prev * next) % mod;
        }

        return sum;
    }
};