class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && (long long)nums[j]==(long long)nums[j - 1] + 1) {
                j++;
            }
            if (i != j - 1)
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            else
                ans.push_back(to_string(nums[i]));
            i = j;
        }
        return ans;
    }
};