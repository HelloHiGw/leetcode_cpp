// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);
//         vector<int> inDegree(numCourses);
//         for (auto &p : prerequisites) {
//             graph[p[1]].push_back(p[0]);
//             ++inDegree[p[0]];
//         }
//         queue<int> q;
//         for (int i = 0; i < numCourses; ++i) {
//             if (inDegree[i] == 0) q.push(i);
//         }
//         vector<int> res;
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             res.push_back(curr);
//             for (int nei : graph[curr]) {
//                 if (--inDegree[nei] == 0) q.push(nei);
//             }
//         }
//         if (res.size() < numCourses) return {};
//         return res;
//     }
// };

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visit(numCourses);
        vector<int> res;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, visit, res)) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &visit, vector<int> &res) {
        if (visit[i] == 1) return false;
        if (visit[i] == 2) return true;
        visit[i] = 1;
        for (int nei : graph[i]) {
            if (!dfs(nei, graph, visit, res)) return false;
        }
        visit[i] = 2;
        res.push_back(i);
        return true;
    } 
};