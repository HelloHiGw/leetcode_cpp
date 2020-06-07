class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int cnt = 0;
        for (int i = 0, j = 0; i < sentence.size(); i = j + 1) {
            word.clear();
            ++cnt;
            for (j = i; j < sentence.size() && sentence[j] != ' '; ++j) word += sentence[j];
            if (match(word, searchWord)) return cnt;
        }
        return -1;
    }
    
private:
    bool match(string& s1, string& s2) {
        if (s1.size() < s2.size()) return false;
        for (int i = 0; i < s2.size(); ++i) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        istringstream in(sentence);
        int cnt = 0;
        while (in >> word) {
            ++cnt;
            if (word.find(searchWord) == 0) return cnt;
        }
        return -1;
    }
};