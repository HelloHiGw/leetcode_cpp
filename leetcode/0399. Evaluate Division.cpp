// rare method, not use this, you will never think this out
// https://www.cnblogs.com/grandyang/p/5880133.html
// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         unordered_map<string, unordered_map<string, double>> m;
//         for (int i = 0; i < equations.size(); ++i) {
//             m[equations[i][0]][equations[i][1]] = values[i];
//             m[equations[i][1]][equations[i][0]] = 1 / values[i];  // values are all positive
//         }
//         vector<double> res;
//         for (auto &q : queries) {
//             unordered_set<string> visited;
//             double ans = calculate(q[0], q[1], m, visited);
//             res.push_back(ans);
//         }
//         return res;
//     }
    
// private:
//     double calculate(string up, string down, unordered_map<string, unordered_map<string, double>> &m, unordered_set<string> &visited) {
//         if (m.count(up) && m[up].count(down)) return m[up][down];
//         for (auto it : m[up]) {
//             if (visited.count(it.first)) continue;
//             visited.insert(it.first);
//             double t = calculate(it.first, down, m, visited);
//             if (t > 0) return it.second * t;
//         }
//         return -1.0;
//     }
// };


//  https://leetcode.com/problems/evaluate-division/discuss/88275/Python-fast-BFS-solution-with-detailed-explantion
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // graph in essence m[a][b] = 2, there is an edge between a and b, and weight is 2
        unordered_map<string, unordered_map<string, double>> m;  
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> res;
        for (auto &query : queries) {
            if (!m.count(query[0]) || !m.count(query[1])) { // vertex unseen
                res.push_back(-1);
                continue;
            }
            queue<pair<string, double>> q;  // node val and edge product from root
            q.push({query[0], 1});
            unordered_set<string> visited;
            visited.insert(query[0]);
            bool found = false;
            while (!q.empty()) {
                for (int i = q.size(); i > 0; --i) {
                    auto p = q.front();
                    q.pop();
                    if (p.first == query[1]) {  // agree with a / a = 1
                        found = true;
                        res.push_back(p.second);
                        break;
                    }
                    for (auto nei : m[p.first]) {
                        if (visited.count(nei.first)) continue;
                        visited.insert(nei.first);
                        nei.second *= p.second;
                        q.push(nei);  // not reference &, no change to m
                    }
                }
            }
            if (!found) res.push_back(-1);
        }
        return res;
    }
};

// but the system seems not work...displays wrong
