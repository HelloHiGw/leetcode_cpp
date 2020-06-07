// // TLE
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> words(wordList.begin(), wordList.end());
//         if (words.count(endWord) == 0) return {};
//         vector<string> path = {beginWord};
//         vector<vector<string>> res;
//         unordered_set<string> visited;
//         visited.insert(beginWord);
//         int shortest = words.size() + 1;
//         backtrack(shortest, endWord, words, visited, path, res);
//         return res;
//     }

// private:
//     void backtrack(int& shortest, string& endWord, unordered_set<string>& words, unordered_set<string>& visited, vector<string>& path, vector<vector<string>>& res) {
//         if (path.back() == endWord) {
//             if (path.size() < shortest) {
//                 res.clear();
//                 res.push_back(path);
//                 shortest = path.size();
//             } else if (path.size() == shortest) {
//                 res.push_back(path);
//             }
//             return;
//         }
//         if (path.size() >= shortest) return;
//         string s = path.back();
//         for (int i = 0; i < s.size(); ++i) {
//             char ch = s[i];
//             for (char c = 'a'; c <= 'z'; ++c) {
//                 s[i] = c;
//                 if (words.count(s) && !visited.count(s)) {
//                     path.push_back(s);
//                     visited.insert(s);
//                     backtrack(shortest, endWord, words, visited, path, res);
//                     path.pop_back();
//                     visited.erase(s);
//                 }
//             }
//             s[i] = ch;
//         }
//     }
// };


// the difference between 127 and this is that 127 do not need the path string, here
// we need path string, so use vector<string>(path) as element of queue


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0) return {};
    
        vector<vector<string>> res;
        // if we want to use queue<vector<string>*> q here, newPath should be deep copy of path
        // how can we implement deep copy of a pointer
        queue<vector<string>> q;  
        q.push({beginWord});
        
        unordered_set<string> visited;
        unordered_set<string> levelVisited;
        levelVisited.insert(beginWord);

        vector<string> path, newPath;
        
        while (!q.empty()) {
            bool reachEnd = false;
            visited.insert(levelVisited.begin(), levelVisited.end());
            levelVisited.clear();
            /*
            the following is the answer of certain test case
            [["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
            
            if you use visited.insert(s), for
            red, ted    red, rex  in the queue
            it will get
            red, ted, tad    red, ted, [tex]   but no red, rex, [tex] because you set tex as visited this level
            
            that is, words in the same level can be used mutiple times
            */
            
            for (int i = q.size(); i > 0; --i) {
                path = q.front();
                q.pop();
                                
                string s = path.back();
                if (s == endWord) {
                    res.push_back(path);
                    reachEnd = true;
                }
    
                for (int i = 0; i < s.size(); ++i) {
                    char ch = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;
                        if (words.count(s) && !visited.count(s)) {
                            levelVisited.insert(s);
                            newPath = path;
                            newPath.push_back(s);  // 127 push s, here push path string ending with s
                            q.push(newPath);
                        }
                    }
                    s[i] = ch;
                }
            }
            if (reachEnd) break;
        }
        return res;
    }
};

void backtrack(int start, string& str, vector<int>& curr, vector<vector<int>>& res) {
    if (start == str.size()) {
        res.push_back(curr);
        return;
    }
    for (int i = start; i < str.size(); ++i) {
        int digit = stoi(str.substr(start, i - start + 1));
        if (digit > 600) break;
        curr.push_back(digit);
        backtrack(i + 1, str, curr, res);
        curr.pop_back();
    }
}



