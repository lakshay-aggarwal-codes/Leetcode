class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {}

    void add(int num) { nums.push_back(num); }

    int getProduct(int k) {
        if (nums.size() < k)
            return -1;
        int ans = 1;
        int count = 0;
        for (int i = nums.size() - 1; i >= 0 && count < k; i--) {
            ans *= nums[i];
            count++;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */