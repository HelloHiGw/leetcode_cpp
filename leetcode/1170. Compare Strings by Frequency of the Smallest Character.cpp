class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freq(12);
        for (string word : words) {
            int fre = f(word);
            ++freq[fre];
        }
        for (int i = 9; i > 0; --i) {
            freq[i] += freq[i + 1];  // freq[i]: the count of word that f(word) >= i
        }
        vector<int> res;
        for (string q : queries) {
            res.push_back(freq[f(q) + 1]);
        }
        return res;
    }
    
    int f(string s) {
        vector<int> v(26);
        for (char ch : s) ++v[ch - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (v[i]) return v[i];
        }
        return 0;
    }
};