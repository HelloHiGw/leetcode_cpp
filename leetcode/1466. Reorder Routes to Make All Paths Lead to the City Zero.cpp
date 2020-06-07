class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : connections) {
            // out edge
            graph[e[0]].push_back({e[1], 1});
            // in edge
            graph[e[1]].push_back({e[0], 0});
        }
        vector<bool> visited(n);
        // return dfs(0, graph, visited);
        return bfs(0, graph, visited);
    }
    
private:
    int dfs(int curr, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
        // cannot set if (visitd[curr]) return 0 here
        // if so, it just compute how many out edges in the graph
        visited[curr] = true;
        int res = 0;
        for (auto& [nei, cost] : graph[curr]) {
            if (visited[nei]) continue;
            res += cost + dfs(nei, graph, visited);
        }
        return res;
    }
    
    int bfs(int curr, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
        visited[curr] = true;
        queue<int> que;
        que.push(curr);
        int res = 0;
        while (!que.empty()) {
            curr = que.front();que.pop();
            for (auto& [nei, cost] : graph[curr]) {
                if (visited[nei]) continue;
                res += cost;
                que.push(nei);
                visited[nei] = true;
            }
        }
        return res;
    }
};