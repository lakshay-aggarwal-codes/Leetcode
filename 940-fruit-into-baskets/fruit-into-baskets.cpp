class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int ans = 0;
        int n = fruits.size();
        unordered_map<int, int> m;

        int type = 0;

        for (int right = 0; right < n; right++) {
            int x = fruits[right];
            if (m.count(x) == 0) {
                m[x] = 1;
                type++;
            } else
                m[x]++;
            while (type > 2) {
                m[fruits[left]]--;
                if (m[fruits[left]] == 0) {
                    type--;
                    m.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};