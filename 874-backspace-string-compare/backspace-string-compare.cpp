class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";
        for (char x : s) {
            if (x == '#') {
               if( !s1.empty())
                s1.pop_back();
            } else
                s1 += x;
        }
        for (char x : t) {
             if (x == '#') {
               if( !s2.empty())
                s2.pop_back();
            } else
                s2 += x;
        }
        return s1 == s2;
    }
};