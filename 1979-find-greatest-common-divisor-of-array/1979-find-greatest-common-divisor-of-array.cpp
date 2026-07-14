class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        auto small = *min_element(nums.begin(), nums.end());
        auto large = *max_element(nums.begin(), nums.end());
        for(int i = 1;i<= large;i++){
            if(small%i ==0  && large%i==0){
                ans = max(ans,i);
            }
        }
        return ans;
    }
};