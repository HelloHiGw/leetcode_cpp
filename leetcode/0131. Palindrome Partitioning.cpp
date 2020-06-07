class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        backtrack(0, s, curr, res);
        return res;
    }
    
    void backtrack(int start, string& s, vector<string>& curr, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            // s[start] to s[i] must be palindrome
            if (!isPalindrome(s, start, i)) continue;
            curr.push_back(s.substr(start, i - start + 1));
            backtrack(i + 1, s, curr, res);
            curr.pop_back();
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};