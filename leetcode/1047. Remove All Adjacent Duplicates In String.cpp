class Solution {
public:
    string removeDuplicates(string S) {
        while (true) {
            bool same = false;
            for (int i = 0; i < (int)S.size() - 1 && !same; ++i) {
                if (S[i] == S[i + 1]) {
                    S.erase(i, 2);
                    same = true;
                }
            }
            if (!same) break;
        }
        return S;
    }
};


class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (int i = 0; i < S.size(); ++i) {
            if (!st.empty() && st.top() == S[i]) {
                st.pop();
            } else {
                st.push(S[i]);
            }
        }
        
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (int i = 0; i < S.size(); ++i) {
            if (!res.empty() && res.back() == S[i]) {
                res.pop_back();
            } else {
                res += S[i];
            }
        }
        return res;
    }
};

/*
in essence, it is the same as above
i is just res.size()
S[i] = S[j] is res += S[j]
S[i] == S[i - 1] is res.pop_back
*/
class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0;
        for (int j = 0; j < S.size(); ++i, ++j) {
            S[i] = S[j];
            if (i && S[i] == S[i - 1]) i -= 2;
        }
        return S.substr(0, i);
    }
};