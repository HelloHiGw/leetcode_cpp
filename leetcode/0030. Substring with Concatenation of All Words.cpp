// /*
// what is the time complexity ?
// O(s.size() * words.size() * len) ? len for computing substr 
// */
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         if (words.empty() || s.empty()) return {};
//         unordered_map<string, int> need;
//         for (string& word : words) ++need[word];
        
//         int len = words[0].size(), count = words.size();
//         vector<int> res;
        
//         // left is moving by step 1, right is moving by step len
//         for (int i = 0; i < (int)s.size() - count * len + 1; ++i) {
//             unordered_map<string, int> window;
//             int j = 0;
            
//             for (; j < count; ++j) {
//                 string word = s.substr(i + j * len, len);
//                 if (!need.count(word)) break;
//                 ++window[word];
//                 if (window[word] > need[word]) break;
//             }
            
//             if (j == count) res.push_back(i);
//         }
        
//         return res;
//     }
// };



/*
O(len * s.size() / len * len) the second len for computing substr
= O(len * s.size())

really hard to understand
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) return {};
        unordered_map<string, int> need;
        for (string& word : words) ++need[word];
        
        int len = words[0].size(), count = words.size();
        vector<int> res;
        
        // left is moving by step 1, right is moving by step len
        for (int i = 0; i < len; ++i) {
            unordered_map<string, int> window;
            int left = i;
            int cnt = 0;
            
            for (int right = i; right <= (int)s.size() - len; right += len) {
                string word = s.substr(right, len);
                
                if (need.count(word)) {
                    ++window[word];
                    
                    if (window[word] <= need[word]) {
                        ++cnt;
                    } else {
                        while (window[word] > need[word]) {
                            string str = s.substr(left, len);
                            --window[str];
                            if (window[str] < need[str]) --cnt;
                            left += len;
                        }
                    }
                    
                    if (cnt == count) {
                        res.push_back(left);
                        --window[s.substr(left, len)];
                        --cnt;
                        left += len;
                    }
                    
                } else {
                    window.clear();
                    left = right + len; // here is crucial
                    cnt = 0;
                }
            }
        }
        
        return res;
    }
};