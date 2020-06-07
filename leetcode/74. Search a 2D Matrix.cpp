class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int nRows = matrix.size(), nCols = matrix[0].size();
        int low = 0, high = nRows * nCols - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int i = mid / nCols, j = mid % nCols;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};