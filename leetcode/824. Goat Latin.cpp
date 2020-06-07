class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int cnt = 0, i = 0;
        while (i < S.size()) {
            ++cnt;
            string word, end;
            if (!isVowel(S[i])) end = S[i++];
            while (i < S.size() && S[i] != ' ') {
                word += S[i];
                ++i;
            }
            word += end.empty() ? "ma" : end + "ma";
            word += string(cnt, 'a');
            res += word;
            if (i < S.size()) res += " ";
            ++i;
        }
        return res;
    }
    
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u';
    }
};