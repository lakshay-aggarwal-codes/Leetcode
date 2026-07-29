class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n)
            return 0;
        r = min(n - r, r);
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > 1000000) {
                return 1000001;
            }
        }
        return ans;
    }

    long long countWays(vector<int>& freq) {
        int n = 0;
        long long ways = 1;
        for (int x : freq) {
            n += x;
        }
        for (int x : freq) {
            ways *= nCr(n, x);
            if (ways > 1000000) {
                return 1000001;
            }
            n -= x;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {

        string ans = "";
        vector<int> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string first = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid = string(1,'a' + i);
            }
            freq[i] = freq[i] / 2;
        }
        long long ways = 0;
        int half = 0;
        for (int x : freq) {
            half += x;
        }
        if (countWays(freq) < k)
            return "";
        for (int i = 0; i < half; i++) {
            for (char c = 'a'; c <= 'z'; c++) {

                if (freq[c - 'a'] == 0)
                    continue;
                freq[c - 'a']--;
                ways = countWays(freq);
                if (ways >= k) {
                    first += c;
                    break;
                }
                k -= ways;
                freq[c - 'a']++;
            }
        }

        string second = first;
        reverse(second.begin(), second.end());
        ans = first + mid + second;

        return ans;
    }
};
