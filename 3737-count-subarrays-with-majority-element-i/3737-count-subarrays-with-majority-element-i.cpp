class BIT{
    vector<int>bit;
    int n;
    public:
    BIT(int n){
        this->n= n;
        bit.assign(n+1,0);
    }
    void update(int idx, int val){
        while(idx<=n){
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    int query(int idx){
        int sum =0;
        while(idx>0){
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                arr.push_back(1);
            } else
                arr.push_back(-1);
        }
        int ans = 0;
    
        vector<int> pre(n+1,0);
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + arr[i-1];
        }

        vector<int>val= pre;
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());

        
        unordered_map<int,int> comp;
        for(int i =0 ;i < val.size();i++){
            comp[val[i]] = i + 1;
        }

       
        BIT bit(val.size());
        for(int x :pre){
            int idx = comp[x];
            ans+=bit.query(idx-1);
            bit.update(idx, 1);
        } 
        return ans;
    }
};