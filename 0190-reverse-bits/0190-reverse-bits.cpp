class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int i = 0;
        while (i < 32) {
            ans = (ans << 1) | n & 1;
            n >>= 1;
            i++;
        }
        return ans;
    }
};