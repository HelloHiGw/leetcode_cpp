class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> pre, res;
        backtrack(0, S, pre, res);
        return res;
    }
    
    void backtrack(int start, string& s, vector<int>& pre, vector<int>& res) {
        if (!res.empty()) return;
        if (start == s.size()) {
            if (pre.size() >= 3) res = pre;
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i - start + 1);
            if (hasLeadingZero(str) || stol(str) > INT_MAX) break;
            int d = stoi(str), n = pre.size();
            // (long) in case of add overflow
            if (n > 1 && (long)pre[n - 2] + pre[n - 1] > d) continue;
            // early terminate
            if (n > 1 && (long)pre[n - 2] + pre[n - 1] < d) break;
            pre.push_back(d);
            backtrack(i + 1, s, pre, res);
            pre.pop_back();
        }
    }

private:
    bool hasLeadingZero(string& s) {
        if (s.empty()) return false;
        if (s.size() == 1 && s[0] == '0') return false;
        return s[0] == '0';
    }
};