class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return prefix[j];
        return prefix[j] - prefix[i - 1];
    }
    
private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */