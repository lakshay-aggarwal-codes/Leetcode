class Solution {
public:
    bool valid(string& s) {
        int n = s.size();

        int value = stoi(s);
        if (value > 255)
            return false;
        if (s.size() > 1 && s[0] == '0')
            return false;

        return true;
    }
    void solve(int idx, string& s, vector<string>& ans, string& curr,
               int part) {
        if (part == 4) {
            if (idx == s.size()) {
                ans.push_back(curr);
            }
            return;
        }

        int remDig = s.size() - idx;
        int remParts = 4 - part;
        if (remDig < remParts || remDig > remParts * 3)
            return;
        for (int len = 1; len < 4; len++) {
            if (idx + len > s.size())
                break;
            string segment = s.substr(idx, len);
            if (!valid(segment))
                continue;
            int oldSize = curr.size();
            if (!curr.empty())
                curr += '.';
            curr += segment;
            solve(idx + len, s, ans, curr, part + 1);
            curr.resize(oldSize);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string curr = "";
        vector<string> ans;
        solve(0, s, ans, curr, 0);
        return ans;
    }
};