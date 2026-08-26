class Solution {
public:
   static bool comparator(int a, int b) {
        string no1 = to_string(a) + to_string(b);
        string no2 = to_string(b) + to_string(a);

        return no1 > no2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        string ans = "";
        for (int c = 0; c < nums.size(); c++) {
            string x = to_string(nums[c]);
            if (c == 0 and x == "0") {
                return "0";
            }
            ans += x;
        }
        return ans;
    }
};