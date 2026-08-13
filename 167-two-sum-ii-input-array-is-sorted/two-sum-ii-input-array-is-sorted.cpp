class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        int n = numbers.size();
        for (int i = 0; i<n; i++) {
            m[numbers[i]] = i + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int other = target - numbers[i];
            ans.push_back(i+1);
            if (m.find(other) != m.end()) {
                ans.push_back(m[other]);
                return ans;
            }
            ans.pop_back();
        }

        return ans;
    }
};