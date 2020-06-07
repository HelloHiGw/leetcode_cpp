class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> visited(N * N + 1, false);
        queue<int> que;
        que.push(1);
        visited[1] = true;
        
        int res = -1;
        while (!que.empty()) {
            ++res;
            for (int i = que.size(); i > 0; --i) {
                int curr = que.front();
                que.pop();
                if (curr == N * N) return res;
                for (int d = 1; d <= 6 && curr + d <= N * N; ++d) {
                    int next = curr + d;
                    int val = getBoardValue(board, next);
                    if (val != -1) next = val;
                    if (!visited[next]) {
                        que.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        return -1;
    }
    
private:
    int getBoardValue(vector<vector<int>>& board, int num) {
        int N = board.size();
        --num;
        int rowFromBottom = num / N;
        int col = (rowFromBottom % 2 == 0) ? num % N : N - 1 - num % N;
        int row = N - 1 - rowFromBottom;
        return board[row][col];
    }
};