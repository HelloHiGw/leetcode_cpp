class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> row(n, false), col(m, false);
        int oddRows = 0, oddCols = 0;
        for (auto index : indices) {
            row[index[0]] = !row[index[0]];
            col[index[1]] = !col[index[1]];
            oddRows += row[index[0]] ? 1 : -1;
            oddCols += col[index[1]] ? 1 : -1;
        }
        return oddRows * (m - oddCols) + oddCols * (n - oddRows);
    }
};