class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while (n > 0) {
            int x = n % 10;
            nums.push_back(x);
            n /= 10;
        }
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        return nums[sz-1]*nums[sz-2];
    }
};