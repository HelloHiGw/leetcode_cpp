class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st(J.begin(), J.end());
        int res = 0;
        for (char ch : S) {
            res += st.count(ch);
        }
        return res;
    }
};