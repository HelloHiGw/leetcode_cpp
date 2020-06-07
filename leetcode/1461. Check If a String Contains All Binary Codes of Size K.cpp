class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> st;
        string curr;
        
        for (int i = 0; i < k - 1; ++i) curr += s[i];
        for (int i = k - 1; i < n; ++i) {
            curr += s[i];
            st.insert(curr);
            curr.erase(curr.begin());
        }
        
        int maxn = pow(2, k);
        return st.size() == maxn;
    }
};