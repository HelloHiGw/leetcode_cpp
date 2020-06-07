// class Solution {
// public:
//     string getHappyString(int n, int k) {
//         vector<string> res;
//         string s;
//         backtrack(n, s, res);
//         if (k > res.size()) return "";
//         return res[k - 1];
//     }
    
// private:
//     void backtrack(int n, string& s, vector<string>& res) {
//         if (n == 0) {
//             res.push_back(s);
//             return;
//         }
//         for (char ch = 'a'; ch <= 'c'; ++ch) {
//             if (!s.empty() && s.back() == ch) continue;
//             s += ch;
//             backtrack(n - 1, s, res);
//             s.pop_back();
//         }
//     }
// };


// time complexity : O(n * k) 
// space complexity : O(n)
class Solution {
public:
    string getHappyString(int n, int k) {
        string res, s;
        backtrack(n, k, s, res);
        return res;
    }
    
private:
    void backtrack(int n, int& k, string& s, string& res) {
        if (!res.empty()) return;  // prune
        if (n == 0) {  // a solution
            if (k-- == 1) res = s; // the kth solution
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ++ch) {
            if (!s.empty() && s.back() == ch) continue;
            s += ch;
            backtrack(n - 1, k, s, res);
            s.pop_back();
        }
    }
};