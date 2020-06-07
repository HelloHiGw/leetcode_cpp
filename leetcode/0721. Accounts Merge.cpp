class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;
        
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;  // a email must belong to only one person
                // build graph email-email, strictly, there should be edges betwenn
                // any account[i] account[j], but it costs much time if doing so
                // so we connect adjacent email to guarantee it is a connected block 
                // it makes no difference for dfs 
                if (i == 1) {
                    if (!graph.count(account[i])) graph[account[i]] = {};  // in case only one email this account
                } else {
                    graph[account[i]].push_back(account[1]);
                    graph[account[1]].push_back(account[i]);
                }
            }
        }
        
        unordered_set<string> visited;
        vector<vector<string>> res;
        for (auto& it : graph) {
            string email = it.first;
            if (!visited.count(email)) {
                vector<string> emails;
                bfs(email, emails, graph, visited);
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), emailToName[email]);
                res.push_back(emails);
            }
        }
        return res;
    }
    
private:
    void dfs(string& email, vector<string>& emails, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited) {
        if (visited.count(email)) return;
        emails.push_back(email);
        visited.insert(email);
        for (string& nei : graph[email]) {
            dfs(nei, emails, graph, visited);
        }
    }
    
    void bfs(string email, vector<string>& emails, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited) {
        queue<string> que;
        que.push(email);
        visited.insert(email);
        
        while(!que.empty()) {
            email = que.front();
            que.pop();
            emails.push_back(email);
            for (string& nei : graph[email]) {
                if (!visited.count(nei)) {
                    que.push(nei);
                    visited.insert(nei);
                }
            }
        }
    }
};





// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         unordered_map<string, string> emailToName;
        
//         for (auto& account : accounts) {
//             string name = account[0];
//             for (int i = 1; i < account.size(); ++i) {
//                 emailToName[account[i]] = name;
//                 father[account[i]] = account[i];  
//                 // not easy to write initialize func, cause we do not konw emails set
//             }
//         }
        
//         for (auto& account : accounts) {
//             for (int i = 2; i < account.size(); ++i) {
//                 union_(account[i], account[i - 1]);
//             }
//         }
        
//         unordered_map<string, vector<string>> unions;
//         for (auto& it : father) {
//             string email = it.first;
//             string root = findFather(email);
//             unions[root].push_back(email);
//         }
        
//         vector<vector<string>> res;
//         for (auto& it : unions) {
//             string name = emailToName[it.first];
//             vector<string> emails = it.second;
//             sort(emails.begin(), emails.end());
//             emails.insert(emails.begin(), name);
//             res.push_back(emails);
//         }
//         return res;
//     }
    
// private:
//     unordered_map<string, string> father;

//     string findFather(string s) {
//         string temp = s;
//         while (father[s] != s) s = father[s];
//         while (temp != s) {
//             string fa = father[temp];
//             father[temp] = s;
//             temp = fa;
//         }
//         return s;
//     }
    
//     void union_(string s1, string s2) {
//         string f1 = findFather(s1), f2 = findFather(s2);
//         if (f1 != f2) father[f1] = f2;
//     }
// };




