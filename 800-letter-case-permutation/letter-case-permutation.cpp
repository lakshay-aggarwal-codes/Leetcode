class Solution {
public:
    void solve(int idx, string curr, vector<string>& ans, string s) {
        int n = s.size();
        if (idx == n) {
            ans.push_back(curr);
            return;
        }
        if (isdigit(s[idx])) {
            curr += s[idx];
            solve(idx + 1, curr, ans, s);
            curr.pop_back();

        } else {

            char x = tolower(s[idx]);
            curr += x;

            solve(idx + 1, curr, ans, s);
            curr.pop_back();

            char y = toupper(s[idx]);
            curr += y;

            solve(idx + 1, curr, ans, s);
            curr.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string curr;
        vector<string> ans;
        solve(0, curr, ans, s);
        return ans;
    }
};