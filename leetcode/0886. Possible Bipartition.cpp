// class Solution {
// public:
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//         vector<vector<int>> graph(N);
//         for (auto& d : dislikes) {
//             graph[d[0] - 1].push_back(d[1] - 1);
//             graph[d[1] - 1].push_back(d[0] - 1);
//         }
        
//         vector<int> color(N, -1);
//         for (int i = 0; i < N; ++i) {
//             if (color[i] == -1 && !bfs(i, 0, graph, color)) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
// private:
//     bool dfs(int i, int c, vector<vector<int>>& graph, vector<int>& color) {
//         if (color[i] != -1) return color[i] == c;
//         color[i] = c;
//         for (int nei : graph[i]) {
//             if (!dfs(nei, 1 - c, graph, color)) return false;
//         }
//         return true;
//     }
    
//     bool bfs(int i, int c, vector<vector<int>>& graph, vector<int>& color) {
//         color[i] = c;
//         queue<int> que;
//         que.push(i);
        
//         while (!que.empty()) {
//             c = 1 - c;
//             for (int j = que.size(); j > 0; --j) {
//                 i = que.front();
//                 que.pop();
//                 for (int nei : graph[i]) {
//                     if (color[nei] == -1) {
//                         que.push(nei);
//                         color[nei] = c;
//                     } else {
//                         if (color[nei] == color[i]) return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        for (auto& d : dislikes) {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }
        initialize(N);
        for (int i = 0; i < N; ++i) {
            if (graph[i].empty()) continue;
            int fx = findFather(i), fy = findFather(graph[i][0]); // dislikes pairs shoud not in the same union
            if (fx == fy) return false;
            
            for (int j = 1; j < graph[i].size(); ++j) {
                int f = findFather(graph[i][j]);
                if (fx == f) return false;
                union_(graph[i][j], graph[i][0]);  // elements in graph[i] should be in the same union
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

