class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0) return 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 0;
        while (!q.empty()) {
            ++level;
            for (int i = q.size(); i > 0; --i) {
                string s = q.front();
                q.pop();
                if (s == endWord) return level;
                for (int j = 0; j < s.size(); ++j) {  // this step is finding neighbors of s in essence
                    char ch = s[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[j] = c;
                        if (words.count(s) && !visited.count(s)) {
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[j] = ch;
                }
            }
        }
        return 0;
    }
};