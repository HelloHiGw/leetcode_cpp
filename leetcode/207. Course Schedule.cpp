class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {  // edge p[1] -> p[0]
            ++inDegree[p[0]];
            graph[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        int num = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nei : graph[curr]) {
                if (--inDegree[nei] == 0) q.push(nei);
            }
            ++num;
        }
        return num == numCourses;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {  // edge p[1] -> p[0]
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visit(numCourses);
        for (int i = 0; i < numCourses; ++i) {  // for various connected blocks
            if (!dfs(i, graph, visit)) return false;
        }
        return true;
    }
    
private:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &visit) {
        if (visit[i] == 1) return false;
        if (visit[i] == 2) return true;  // prune, such as 5->4->3->2->1->0
        visit[i] = 1;  // set the path node as being visited
        for (int nei : graph[i]) {
            if (!dfs(nei, graph, visit)) return false;
        }
        visit[i] = 2;
        return true;
    }
};
/*
0: not visted
1: is being visited
2: visited
*/