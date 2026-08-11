class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                sum += nums[i];
            } else
                break;
        }
        for(int i =0;i < n;i++){
            if(nums[i] == sum ){
                sum++;i=-1;
            }
        }
        return sum;
    }
};