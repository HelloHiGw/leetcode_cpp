class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1 + n2);
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j + 1, pos2 = i + j;
                int sum = mul + v[pos1];
                v[pos1] = sum % 10;
                v[pos2] += sum / 10;
            }
        }
        string res;
        for (int num : v) {
            if (res.size() > 0 || num) res += num + '0';
        }
        return res.empty() ? "0" : res;
    }
};

//  `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]` 