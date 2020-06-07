class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {  // set 1 as center and find arounding 0s level by level
                    q.push({i, j});
                }
            }
        }
        
        int steps = -1;  // first round, elements in queue is 1s
        while (!q.empty()) {
            ++steps;
            for (int k = q.size(); k > 0; --k) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (auto &d : dirs) {
                    int newI = i + d[0], newJ = j + d[1];
                    if (isValid(newI, newJ, grid, visited)) {
                        q.push({newI, newJ});
                        visited[newI][newJ] = true;  // avoid duplicate visiting
                    }
                }
            }
        }
        return steps == 0 ? -1 : steps;
    }
    
private:
    bool isValid(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 0 && !visited[i][j];
    }
    
};