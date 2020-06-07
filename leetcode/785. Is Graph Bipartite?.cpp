class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] == 0 && !dfs(i, color, 1, graph)) return false;
            // if (color[i] == 0 && !bfs(i, color, 1, graph)) return false;
        }
        return true;
    }

private:
    bool dfs(int curr, vector<int> &color, int c, vector<vector<int>> &graph) {
        color[curr] = c;
        for (int nei : graph[curr]) {
            if (color[nei] == 0) {
                if (!dfs(nei, color, -c, graph)) return false;
            } else if (color[nei] == c) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int curr, vector<int> &color, int c, vector<vector<int>> &graph) {
        if (color[curr]) return color[curr] == c;
        color[curr] = c;
        for (int nei : graph[curr]) {
            if (!dfs(nei, color, -c, graph)) return false;
        }
        return true;
    }
    
    bool bfs(int curr, vector<int> &color, int c, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(curr);
        color[curr] = c;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (int nei : graph[curr]) {
                if (color[nei] == 0) {
                    color[nei] = -color[curr];
                    q.push(nei);
                } else if (color[nei] == color[curr]) {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    // treat (i, graph[i][j]) as a dislike pair, the two can not stay in the same group
    bool isBipartite(vector<vector<int>>& graph) {
        initialize(graph.size());  // graph.size() = n
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;  // no neighbors for i
            int f1 = findFather(i), f2 = findFather(graph[i][0]);  // no same union for two edge nodes
            if (f1 == f2) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                f2 = findFather(graph[i][j]);
                if (f1 == f2) return false;
                union_(graph[i][j], graph[i][0]);  // same union if both have edge to i
            }
            
        }
        return true;
    }
    
private:
    vector<int> father;
    
    void initialize(int N) {
        for (int i = 0; i < N; ++i) {
            father.push_back(i);
        }
    }
    
    int findFather(int x) {
        int t = x;
        while (x != father[x]) x = father[x];
        while (t != x) {
            int f = father[t];
            father[t] = x;
            t = f;
        }
        return x;
    }
    
    void union_(int x, int y) {
        int fx = findFather(x), fy = findFather(y);
        if (fx != fy) father[fx] = fy;
    }
};