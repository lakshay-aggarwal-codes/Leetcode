class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            if (st.empty()) {
                ans[i] = 0;
            }
            st.push(i);
        }
        return ans;
    }
};