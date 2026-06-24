class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> hm;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            int other = target - nums[i];

            if(hm.find(other) != hm.end()){
                return {i, hm[other]};
            }else{
                hm[nums[i]] = i;
            }
        }
        return {};
    }
};