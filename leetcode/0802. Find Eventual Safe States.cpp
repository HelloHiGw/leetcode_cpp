class Solution {
public:
    /*
    the same as topoSort except we need outDegree and graphIn
    e.g. 0->1->2->0  2->3 2->4
    topoSort can judge there is a circle, cnt = 0 < n = 5, but can not tell which vertex that can reach a circle or not
    outDegree and graphIn can
    */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> graphIn(graph.size());  // out edge graph to in edge graph
        vector<int> outDegree(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int nei : graph[i]) graphIn[nei].push_back(i);
            outDegree[i] = graph[i].size();
        }
    
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < graph.size(); ++i) {
            if (outDegree[i] == 0) {
                q.push(i);
                res.push_back(i);  // outDegree is 0, it must not on a path which can reach a circle
            }
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nei : graphIn[curr]) {
                if (--outDegree[nei] == 0) {
                    q.push(nei);
                    res.push_back(nei);
                }
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 0 not visited   1 is being visited (not safe state)    2 visited (safe state)
        vector<int> visit(graph.size(), 0);
        vector<int> res;
        for (int i = 0; i < graph.size(); ++i) {  // after for loop, visit[i] = 1 for vertexes which can reach a circle otherwise visit[i] = 2
            if (dfs(i, graph, visit)) res.push_back(i);
        }
        return res;
    }
    
private:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &visit) {
        if (visit[i] == 1) return false;
        if (visit[i] == 2) return true;
        visit[i] = 1;
        for (int nei : graph[i]) {
            if (!dfs(nei, graph, visit)) return false;  // if return false, the state is 1(before set visit[i] = 2)
        }
        visit[i] = 2;
        return true;
    }
};