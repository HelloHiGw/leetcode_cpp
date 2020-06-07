class Solution {
public:
    bool isAdditiveNumber(string num) {
        string twoStepsBefore, oneStepBefore;
        return backtrack(1, 0, num, twoStepsBefore, oneStepBefore);
    }
    
    bool backtrack(int k, int start, string& num, string& twoStepsBefore, string& oneStepBefore) {
        if (start == num.size()) {
            return k > 3;  // at least three numbers
        }
        for (int i = start; i < num.size(); ++i) {
            string curr = num.substr(start, i - start + 1);
            if (hasLeadingZeros(curr)) break;  // leading zero
            if (k < 3) {
                if (backtrack(k + 1, i + 1, num, oneStepBefore, curr)) return true;
            } else {
                int cmp = compare(twoStepsBefore, oneStepBefore, curr);
                // int cmp = 1;
                // long long d1 = stoll(twoStepsBefore), d2 = stoll(oneStepBefore), d = stoll(curr);
                // if (d1 + d2 == d) cmp = 0;
                // else if (d1 + d2 < d) cmp = -1;
                if (cmp < 0) break;  // prune
                if (cmp == 0) {
                    if (backtrack(k + 1, i + 1, num, oneStepBefore, curr)) return true;
                }
            }
        }
        return false;
    }
    
private:
    
    bool hasLeadingZeros(string& s) {
        if (s.empty()) return false;
        if (s.size() == 1 && s[0] == '0') return false;
        return s[0] == '0';
    }
    
    int compare(string& s1, string& s2, string& s) {
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0;
        string sum;
        while (i >= 0 || j >= 0 || carry) {
            int d1 = (i >= 0 ? s1[i] - '0': 0);
            int d2 = (j >= 0 ? s2[j] - '0': 0);
            --i;
            --j;
            int temp = d1 + d2 + carry;
            sum += to_string(temp % 10);
            carry = temp / 10;
        }
        reverse(sum.begin(), sum.end());
        if (sum.size() > s.size()) return 1;
        if (sum.size() < s.size()) return -1;
        i = sum.size() - 1, j = s.size() - 1;
        while (i >= 0 && j >= 0) {
            if (sum[i] != s[j]) {
                return sum[i] > s[j] ? 1 : -1; // not reurn sum[i] > s[j], or it will be 1 and 0 for true false
            }
            --i;
            --j;
        }
        return 0; // equal
    }
};