    class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1)
                return "1";
            string s = "1";
            for (int i = 1; i < n; i++) {
                string ans = "";
                int j = 0;
                while (j < s.size()) {
                    int count = 0;
                    char ch = s[j];
                    while (j < s.size() && s[j] == ch) {
                        count++;
                        j++;
                    }
                    ans += to_string(count);
                    ans += ch;
                }
                s = ans;
            }
            return s;
        }
    };