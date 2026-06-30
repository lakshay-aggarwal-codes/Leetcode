class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0, j = 0;
        unordered_set<char> st;

        while (j < n) {

            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};