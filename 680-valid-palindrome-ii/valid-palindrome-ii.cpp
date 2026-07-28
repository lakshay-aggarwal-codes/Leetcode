class Solution {
public:
    bool palin(string& s, int st, int end) {

        while (st < end) {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return palin(s, l + 1, r) || palin(s, l, r - 1);
            }
        }
        return true;
    }
};