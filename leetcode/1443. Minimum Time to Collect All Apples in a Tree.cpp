// class Solution {
// public:
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         vector<vector<int>> graph(n);
//         for (const auto& e : edges) {  // directed graph (from < to)
//             graph[e[0]].push_back(e[1]);
//         }
//         return dfs(0, graph, hasApple);
//     }

// private:
//     int dfs(int curr, vector<vector<int>>& graph, vector<bool>& hasApple) {
//         int total = 0;
//         for (int child : graph[curr]) {
//             int cost = dfs(child, graph, hasApple);
//             if (cost > 0 || hasApple[child]) {  // either child has an apple or substree of child has apple(s), we visit child (+2)
//                 total += 2 + cost;
//             }
//         }
//         return total;
//     }
// };


class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {  // undirected graph (no order between from and to)
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, graph, hasApple, visited);
    }

private:
    int dfs(int curr, vector<vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited) {
        int total = 0;
        visited[curr] = true;
        for (int child : graph[curr]) {
            if (visited[child]) continue;
            int cost = dfs(child, graph, hasApple, visited);
            if (cost > 0 || hasApple[child]) {
                total += 2 + cost;
            }
        }
        return total;
    }
};