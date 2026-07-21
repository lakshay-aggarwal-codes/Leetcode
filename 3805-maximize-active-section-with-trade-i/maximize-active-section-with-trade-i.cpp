class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int>> blocks;
        int totalOne = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                totalOne++;
            }
        }
        // s = '0' + s + '0';
        int maxGain = 0;
        int i = 0;
        int n = s.size();
        while (i < s.size()) {
            char curr = s[i];
            int occ = 0;
            while (i < n && s[i] == curr) {
                occ++;
                i++;
            }
            blocks.push_back({curr, occ});
        }

        for (int i = 1; i < blocks.size() - 1; i++) {
            if (blocks[i].first == '1') {
                if (blocks[i - 1].first == '0' && blocks[i + 1].first == '0') {
                    int x = blocks[i - 1].second + blocks[i + 1].second;
                    maxGain = max(maxGain, x);
                }
            }
        }
        return maxGain + totalOne;
    }
};
