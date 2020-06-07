class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int cnt = 0;  // connected blocks
        for (int i = 0; i < rooms.size(); ++i) {
            if (!visited[i]) {
                if (cnt == 1) return false;
                dfs2(i, rooms, visited);
                ++cnt;
            }
        }
        return true;
    }
    
private:
    void dfs1(int i, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[i] = true;
        for (int nei : graph[i]) {
            if (visited[nei]) continue;
            dfs(nei, graph, visited);
        }
    }
    
    void dfs2(int i, vector<vector<int>> &graph, vector<bool> &visited) {
        stack<int> st;
        st.push(i);
        visited[i] = true;
        while (!st.empty()) {
            i = st.top();
            st.pop();
            for (int nei : graph[i]) { 
                // the first nei is push first, so visit last
                // like the tree, you push right first, then left, so is preorder
                if (visited[nei]) continue;
                st.push(nei);
                visited[nei] = true;
            }
        }
    }
    
    void bfs(int i, vector<vector<int>> &graph, vector<bool> &visited) {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            i = q.front();
            q.pop();
            for (int nei : graph[i]) {
                if (visited[nei]) continue;
                q.push(nei);
                visited[nei] = true;
            }
        }
    }
};