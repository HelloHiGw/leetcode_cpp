// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& M) {
//         vector<bool> visited(M.size(), false);
//         int res = 0;
//         for (int i = 0; i < M.size(); ++i) {
//             if (!visited[i]) {
//                 bfs(i, M, visited);
//                 ++res;
//             }
//         }
//         return res;
//     }
    
// private:
//     void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
//         visited[i] = true;
//         for (int j = 0; j < M[i].size(); ++j) {
//             if (M[i][j] == 1 && !visited[j]) {
//                 dfs(j, M, visited);
//             }
//         }
//     }
    
//     void bfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
//         queue<int> que;
//         que.push(i);
//         visited[i] = true;
        
//         while (!que.empty()) {
//             i = que.front();
//             que.pop();
//             for (int j = 0; j < M[i].size(); ++j) {
//                 if (M[i][j] == 1 && !visited[j]) {
//                     que.push(j);
//                     visited[j] = true;
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        initialize(M.size());
        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M[0].size(); ++j) {
                if (M[i][j] == 1) {
                    union_(i, j);
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (findFather(i) == i) ++res;
        }
        return res;
    }
    
private:
    vector<int> father;
    
    void initialize(int n) {
        for (int i = 0; i < n; ++i) {
            father.push_back(i);
        }
    }
    
    int findFather(int x) {
        int t = x;
        while (x != father[x]) {
            x = father[x];
        }
        
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