class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int i = A.size() - 1, carry = 0;
        while (i >= 0 || K != 0 || carry != 0) {
            int num1 = (i >= 0 ? A[i] : 0);
            int num2 = (K != 0 ? K % 10 : 0);
            --i;
            K /= 10;
            int sum = num1 + num2 + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};