/*
topoSort
time O(n ^ 2)
space O(n ^ 2)
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
        for (auto& v : p) {
            graph[v[0]].push_back(v[1]);
            ++inDegree[v[1]];
        }
        
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) que.push(i);
        }
        
        vector<unordered_set<int>> prevs(n);
        
        while (!que.empty()) {
            int curr = que.front();que.pop();
            for (int nei : graph[curr]) {
                for (int prev : prevs[curr]) {
                    prevs[nei].insert(prev);
                }
                prevs[nei].insert(curr);
                if (--inDegree[nei] == 0) que.push(nei);
            }
        }
        
        vector<bool> res;
        for (auto& v : queries) {
            if (prevs[v[1]].count(v[0])) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

/*
dfs + memo
time O(n ^ 2) ? there are O(n^2) states
space O(n ^ 2) ?
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (auto& v : p) {
            graph[v[0]].push_back(v[1]);
        }
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        vector<bool> res;
        for (auto &q : queries) {
            bool reach = dfs(q[0], q[1], graph, memo);
            res.push_back(reach);
        }
        return res;
    }
    
private:
    bool dfs(int start, int target, vector<vector<int>>& graph, vector<vector<int>>& memo) {
        if (start == target) return true;
        if (memo[start][target] != -1) return memo[start][target];
        
        int reach = 0;
        for (int nei : graph[start]) {
            if (dfs(nei, target, graph, memo)) {
                reach = 1;
                break;
            }
        }
        return memo[start][target] = reach;
    }
};


/*
floyd
time O(n ^ 3)
space O(n^2)
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& queries) {
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for (auto& v : p) {
            connected[v[0]][v[1]] = true;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    connected[i][j] = connected[i][j] || connected[i][k] && connected[k][j];
                }
            }
        }
        
        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(connected[q[0]][q[1]]);
        }
        return res;
    }
};

