class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        stack<int>st;
        for(int i=0;i< n;i++){
            if(st.empty() || nums[i]< nums[st.top()]){
                st.push(i);
            }
        }

        for(int j =n-1;j>=0;j--){
            while(!st.empty() && nums[st.top()]<= nums[j]){
                ans = max(j -st.top(), ans);
                st.pop();
            }
        }
        return ans;
    }
};