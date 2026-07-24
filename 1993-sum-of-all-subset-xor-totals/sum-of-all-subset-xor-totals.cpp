class Solution {
public:
int sum = 0;
    void solve(int idx, vector<int>& nums, int curr){
        int n = nums.size();
        if(idx == n){
            sum += curr;
            return;
        } 
        solve(idx+1, nums, curr^nums[idx]); 
        solve(idx+1, nums, curr);
    }
    int subsetXORSum(vector<int>& nums) {
    solve(0, nums, 0);
     return sum;   
    }
};