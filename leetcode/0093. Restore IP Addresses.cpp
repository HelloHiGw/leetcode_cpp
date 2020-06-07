class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string curr;
        vector<string> res;
        backtrack(4, 0, s, curr, res);
        return res;
    }
    
    // k = 4 parts
    void backtrack(int k, int start, string& s, string curr, vector<string>& res) {
        if (k == 0) {
            if (start == s.size()) {
                curr.pop_back();
                res.push_back(curr);
            }
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i - start + 1);
            int d = stoi(str);
            // leading zeros
            if (d > 255 || to_string(d).size() != str.size()) break;
            backtrack(k - 1, i + 1, s, curr + str + '.', res);
        }
    }
};


// class Solution {
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> res;
//         for (int a = 1; a <= 3; ++a)
//             for (int b = 1; b <= 3; ++b)
//                 for (int c = 1; c <= 3; ++c)
//                     for (int d = 1; d <= 3; ++d) {
//                         if (a + b + c + d == s.size()) { // attention size equal
//                             int d1 = stoi(s.substr(0, a));
//                             int d2 = stoi(s.substr(a, b));
//                             int d3 = stoi(s.substr(a + b, c));
//                             int d4 = stoi(s.substr(a + b + c, d));
//                             if (d1 < 256 && d2 < 256 && d3 < 256 && d4 < 256) {
//                                 string str = to_string(d1) + '.' + to_string(d2) + '.' + to_string(d3) + '.' + to_string(d4);
//                                 if (str.size() == s.size() + 3) res.push_back(str);
//                             }   
//                         }                        
//                     }
//         return res;       
//     }
// };