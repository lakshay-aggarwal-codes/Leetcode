    class Solution {
    public:
        string minWindow(string s, string t) {
            string ans = "";
            if (s.size() < t.size()) {
                return ans;
            }
            unordered_map<char, int> need;
            for (int i = 0; i < t.size(); i++) {
                need[t[i]]++;
            }
            unordered_map<char, int> window;
            int reqd = t.size();
            if(reqd == 0) return "";
            int start = 0;
            int minLength = INT_MAX;
            int left = 0;
            for (int right = 0; right < s.size(); right++) {
                if (need[s[right]] > window[s[right]]) {
                    reqd--;
                }
                window[s[right]]++;
                while (reqd == 0) {
                    if (right - left + 1 < minLength) {
                        start = left;
                        minLength = min(minLength, right - left + 1);
                    }
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]]) {
                        reqd++;
                    }
                    left++;
                }
            }
            if (minLength == INT_MAX)
                return "";
            ans = s.substr(start, minLength);
            return ans;
        }
    };