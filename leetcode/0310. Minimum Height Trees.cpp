class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n);  // for graph[nei].erase(curr) convenience, vector can only ease position
        for (auto &e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) q.push(i);  // leaf
        }
        while (n > 2) {
            n -= q.size();
            for (int i = q.size(); i > 0; --i) {
                int curr = q.front();
                q.pop();
                for (int nei : graph[curr]) {
                    graph[nei].erase(curr);
                    if (graph[nei].size() == 1) q.push(nei);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// like peeling bamboo shoot layer by layer from outside to inside