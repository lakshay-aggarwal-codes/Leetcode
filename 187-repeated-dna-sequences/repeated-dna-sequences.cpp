class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        int n = s.size();
        unordered_set<string> repeat;
        vector<string> ans;
        for (int i = 0; i+9 < n; i++) {
            string curr = ""; 
            for (int j = i; j <= i + 9; j++) {
                curr += s[j];
            }
            if (seen[curr] > 0) {
                repeat.insert(curr);
            }
            seen[curr]++;
            }
        

        for (string x : repeat) {
            ans.push_back(x);
        }
        return ans;
    }
};