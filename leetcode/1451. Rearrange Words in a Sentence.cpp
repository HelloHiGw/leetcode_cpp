// n is word count  L = text.size()
// O(L + n * logn + n)   O(n) + O(L)(res)
class Solution {
public:
    string arrangeWords(string text) {
        if (text.empty()) return "";
        vector<string> words;
        vector<int> index;
        text[0] = tolower(text[0]);
        for (int i = 0, j = 0; i < text.size(); i = j + 1) {
            for (j = i; j < text.size() && text[j] != ' '; ++j);
            index.push_back(words.size());
            words.push_back(text.substr(i, j - i));
        }
        sort(index.begin(), index.end(), [&words](int i, int j){
            if (words[i].size() != words[j].size()) return words[i].size() < words[j].size();
            return i < j;
        });
        
        string res;
        for (int i : index) {
            res += words[i] + ' ';
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};

// bucket sort 
// n : number of words  L : text.size()
// time complexity O(L + n)
// space complexity O(L + n)  (unordered_map O(n), res O(L))
class Solution {
public:
    string arrangeWords(string text) {
        unordered_map<int, vector<string>> m;
        text[0] = tolower(text[0]);
        for (int i = 0, j = 0; i < text.size(); i = j + 1) {
            for (j = i; j < text.size() && text[j] != ' '; ++j);
            int len = j - i;
            m[len].push_back(text.substr(i, len));
        }
        
        string res;
        for (int i = 1; i <= text.size(); ++i) {
            if (m.count(i)) {
                for (string& s : m[i]) res += s + " ";
            }
        }

        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};

