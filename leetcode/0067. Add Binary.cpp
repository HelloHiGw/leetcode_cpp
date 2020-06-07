class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int d1 = i >= 0 ? a[i] - '0' : 0;
            int d2 = j >= 0 ? b[j] - '0' : 0;
            res = to_string((d1 + d2 + carry) % 2) + res;
            carry = (d1 + d2 + carry) / 2;
            -- i;
            -- j;
        }
        return res;
    }
};