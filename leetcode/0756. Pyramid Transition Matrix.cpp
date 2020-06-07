// hashMap + backtracking
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for (string s : allowed) {
            m[s.substr(0, 2)].push_back(s[2]);
        }
        return backtrack(0, bottom, "", m);
    }
    
private:
    bool backtrack(int index, string bottom, string s, unordered_map<string, vector<char>>& m) {
        if (bottom.size() == 1) return true;
        if (s.size() + 1 == bottom.size()) {
            return backtrack(0, s, "", m);
        }
        string prefix = bottom.substr(index, 2);
        for (char ch : m[prefix]) {
            if (backtrack(index + 1, bottom, s + ch, m)) return true;
        }
        return false;
    }
};
