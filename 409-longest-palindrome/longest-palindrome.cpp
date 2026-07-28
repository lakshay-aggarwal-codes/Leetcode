class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        vector<int> freq(52);
        for (char c : s) {
            int index;
            if (islower(c))
                index = c - 'a';
            else
                index = c - 'A' + 26;

            freq[index]++;
        }
        int odd = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] % 2 == 0) {
                ans += freq[i];
            } else {
                ans += freq[i] - 1;
            }
            if (freq[i] % 2 != 0) {
                odd++;
            }
        }
        if (odd > 0)
            ans++;
        return ans;
    }
};