class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N + 1);
        int res = 0;
        backtrack(N, 1, visited, res);
        return res;
    }
    
    void backtrack(int N, int curr, vector<bool>& visited, int& res) {
        if (curr == N + 1) {
            ++res;
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue;
            if (i % curr != 0 && curr % i != 0) continue;
            visited[i] = true;
            backtrack(N, curr + 1, visited, res);
            visited[i] = false;
        }
    }
};