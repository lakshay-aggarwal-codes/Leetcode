class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        int i = 0;
        bool ans = true;
        int prev = 10;
        while ( n >= prev) { 
            n -= prev;
            prev--;
            ans=!ans;
        }
        return !ans;
    }
};