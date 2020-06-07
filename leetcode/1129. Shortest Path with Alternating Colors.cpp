class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));  // graph[0] red graph[1] blue
        for (auto &red : red_edges) {
            graph[0][red[0]].push_back(red[1]);
        }
        for (auto &blue : blue_edges) {
            graph[1][blue[0]].push_back(blue[1]);
        }
        
        vector<vector<int>> res(2, vector<int>(n, 2 * n));  //res[0][i] red reach i, res[1][i] blue reach i
        queue<pair<int, int>> q;  // vertex index and color
        q.push({0, 0});  // red
        q.push({0, 1});  // blue
        res[0][0] = res[1][0] = 0;
        
        // bfs template in essence (get the shortest path), slight difference in get neighbors
        while (!q.empty()) {
            int v = q.front().first, c = q.front().second;  // vertex and color
            q.pop();
            for (int nei : graph[1 - c][v]) {  // red to blue, blue to red
                if (res[1 - c][nei] == 2 * n) {  // not visited
                    res[1 - c][nei] = res[c][v] + 1;
                    q.push({nei, 1 - c});
                }
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int t = min(res[0][i], res[1][i]);
            ans[i] = (t == 2 * n) ? -1 : t;
        }
        return ans;
    }
};

/*
The maximum result (2n - 3) happens when in a path from 0 to target, all the intermediate 
nodes (excluding 0 and target) have an additional self-edge. e.g.

red_edges = [[0, 1], [1, 2], [2, 3]]
blue_edges = [[1, 1], [2, 2]]
n = 4
The minimum step to reach 3 is 5 steps, because all intermediate nodes 1 and 2 
contain self-edges. In other words, the maximum result can be n - 1 + n - 2 = 2n - 3

*/