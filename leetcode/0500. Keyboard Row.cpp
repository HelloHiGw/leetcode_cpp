class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> v = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> mp(26);
        for (int i = 0; i < v.size(); ++i) {
            for (char ch : v[i]) mp[ch - 'a'] = i;
        }
        
        vector<string> res;
        for (string& word : words) {
            bool flag = true;
            for (int i = 1; i < word.size() && flag; ++i) {
                if (mp[tolower(word[i]) - 'a'] != mp[tolower(word[i - 1]) - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        
        return res;
    }
};