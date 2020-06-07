class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = (i >= 0 ? num1[i] - '0' : 0);
            int d2 = (j >= 0 ? num2[j] - '0' : 0);
            --i;
            --j;
            int sum = d1 + d2 + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};