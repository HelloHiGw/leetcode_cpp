/*
O(N * N * L)
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (string& word : words) {
            for (string& word2 : words) {
                if (word2 == word) continue;
                if (word2.find(word) != string::npos) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

/*
O(NlogN + N * N * L)
faster than above, because only search in half space(j = i + 1)
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string& s1, string& s2){
            return s1.size() < s2.size();
        });
        
        vector<string> res;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};