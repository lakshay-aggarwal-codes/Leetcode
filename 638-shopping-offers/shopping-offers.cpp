class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special,
              vector<int>& needs, unordered_map<string, int>& dp) {

        int n = price.size();
        int ans = 0;
        int cost = 0;
        int m = special.size();
        string key = "";
        for (int i = 0; i < n; i++) {
            int x = needs[i];
            string s = to_string(x);
            key += s; 
            key += ",";
        }
        bool exist = false;
        if(dp.count(key)){
            exist = true;
        }
        if (exist) {
            return dp[key];
        }

        for (int i = 0; i < n; i++) {
            ans += price[i] * needs[i];
        }
        for (int i = 0; i < m; i++) {
            bool valid = true;
            vector<int> newNeeds(n);
            for (int j = 0; j < n; j++) {
                if (special[i][j] > needs[j]) {
                    valid = false;
                    break;
                }
                newNeeds[j] = needs[j] - special[i][j];
            }

            if (valid) {
                cost = special[i][n] + solve(price, special, newNeeds, dp);
                ans = min(ans, cost);
            }
        }
        dp[key] = ans;
        return ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {

        unordered_map<string, int> dp;
        int ans = solve(price, special, needs, dp);
        return ans;
    }
};
