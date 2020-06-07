class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int temp = digits[i] + carry;
            res.push_back(temp % 10);
            carry = temp / 10;
        }
        if (carry == 1) res.push_back(carry);
        return vector<int>(res.rbegin(), res.rend());
    }
};