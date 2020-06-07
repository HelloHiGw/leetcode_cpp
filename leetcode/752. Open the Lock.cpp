class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.count("0000") || st.count(target)) return -1;
        
        queue<string> que;
        que.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        int level = -1;
        
        while (!que.empty()) {
            ++level;
            for (int i = que.size(); i > 0; --i) {
                string s = que.front();
                que.pop();
                if (s == target) return level;
                for (string nei : getNeighbors(s)) {
                    if (!visited.count(nei) && !st.count(nei)) {
                        que.push(nei);
                        visited.insert(nei);
                    }
                }
            }
        }
        return -1;
    }
    
private:
    vector<string> getNeighbors(string &s) {
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            int d = s[i] - '0';
            s[i] = (d + 1) % 10 + '0';
            res.push_back(s);
            s[i] = (d - 1 + 10) % 10 + '0';
            res.push_back(s);
            s[i] = d + '0';
        }
        return res;
    }
};