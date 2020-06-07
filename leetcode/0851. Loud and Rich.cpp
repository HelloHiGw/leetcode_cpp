// class Solution {
// public:
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         vector<vector<int>> graph(quiet.size());
//         for (auto& r : richer) {  // directed graph  poor to rich
//             graph[r[1]].push_back(r[0]);
//         }
        
//         vector<int> res(quiet.size(), -1);
//         for (int i = 0; i < quiet.size(); ++i) {
//             res[i] = bfs(i, graph, quiet, res);
//         }
//         return res;
//     }
    
// private:
//     int dfs(int i, vector<vector<int>>& graph, vector<int>& quiet, vector<int>& res) {
//         if (res[i] != -1) return res[i];
//         int quietest = i;
//         for (int nei : graph[i]) {
//             int next = dfs(nei, graph, quiet, res);
//             if (quiet[next] < quiet[quietest]) quietest = next;
//         }
//         return quietest;
//     }
    
//     int bfs(int i, vector<vector<int>>& graph, vector<int>& quiet, vector<int>& res) {
//         int quietest = i;
//         queue<int> que;
//         que.push(i);
        
//         while (!que.empty()) {
//             i = que.front();
//             que.pop();
//             for (int nei : graph[i]) {
//                 if (res[nei] != -1) {
//                     if (quiet[res[nei]] < quiet[quietest]) quietest = res[nei];
//                 } else {
//                     que.push(nei);
//                     if (quiet[nei] < quiet[quietest]) quietest = nei;
//                 }
//             }
//         }
//         return quietest;
//     }
// };


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph(quiet.size());
        vector<int> inDegree(quiet.size());
        for (auto& r : richer) {  // directed graph rich to poor
            graph[r[0]].push_back(r[1]);
            ++inDegree[r[1]];
        }
        
        queue<int> q;
        for (int i = 0; i < quiet.size(); ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        vector<int> res(quiet.size());
        for (int i = 0; i < quiet.size(); ++i) {
            res[i] = i;
        }
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int nei : graph[i]) {
                if (quiet[res[nei]] > quiet[res[i]]) res[nei] = res[i];  // not quiet[res[nei]] > quiet[i]
                if (--inDegree[nei] == 0) q.push(nei);
            }
        }
        
        return res;
    }
};