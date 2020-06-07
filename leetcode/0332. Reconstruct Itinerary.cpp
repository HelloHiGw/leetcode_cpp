// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         // there may be ["JFK", "SFO"], ["SFO", "JFK"], ["JFK", "SFO"], ["SFO", "JFK"]...so use multiset
//         // set for lexical order
//         unordered_map<string, multiset<string>> graph;
//         for (auto &t : tickets) {
//             graph[t[0]].insert(t[1]);
//         }
//         vector<string> res;
//         dfs("JFK", graph, res);
//         reverse(res.begin(), res.end());
//         return res;
//     }
    
// private:
//     void dfs(string s, unordered_map<string, multiset<string>> &graph, vector<string> &res) {
//         while (!graph[s].empty()) {
//             string next = *graph[s].begin();
//             graph[s].erase(graph[s].begin());  // Eulerian path, erase visited path for visiting only once
//             dfs(next, graph, res);
//         }
//         res.push_back(s);
//     }
// };

/*
Eulerian path means visit each "EDGE" once and only once.

visiting each node once and only once is called Hamiltonian.

Input:
[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]

Expected:
["JFK","NRT","JFK","KUL"]

not:
["JFK","KUL","NRT","JFK"]
*/


// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;  // priority_queue is the same as multiset
//         for (auto &t : tickets) {
//             graph[t[0]].push(t[1]);
//         }
//         vector<string> res;
//         dfs("JFK", graph, res);
//         reverse(res.begin(), res.end());
//         return res;
//     }
    
// private:
//     void dfs(string s, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, vector<string> &res) {
//         while (!graph[s].empty()) {
//             string next = graph[s].top();
//             graph[s].pop();  // Eulerian path, erase visited path for visiting only once
//             dfs(next, graph, res);
//         }
//         res.push_back(s);
//     }
// };

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto &t : tickets) {
            graph[t[0]].insert(t[1]);
        }
        vector<string> res;
        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {  // manually implementation of stack
            string s = st.top();
            if (!graph[s].empty()) {
                st.push(*graph[s].begin());
                graph[s].erase(graph[s].begin());
            } else {
                res.push_back(s);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};