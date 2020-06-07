class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, "", 0, res);
        return res;
    }
    
    void backtrack(string S, string curr, int index, vector<string>& res) {
        if (index == S.size()) {
            res.push_back(curr);
            return;
        }
        backtrack(S, curr + S[index], index + 1, res);
        if (isalpha(S[index])) {
            char ch = isupper(S[index]) ? tolower(S[index]) : toupper(S[index]);
            backtrack(S, curr + ch, index + 1, res);
        }
    }
};