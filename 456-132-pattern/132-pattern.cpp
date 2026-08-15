class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
            int second = INT_MIN;
            for(int i = nums.size()-1;i>=0;i--){
                while(!st.empty() && nums[i]> nums[st.top()]){
                    second = nums[st.top()];
                    st.pop();
                }
                if(nums[i] < second) return true;
                st.push(i);
            }
            return false;
    }
};