class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0; i <= rowIndex; ++i) {
            row.insert(row.begin(), 1);
            for (int j = 1; j < i; ++j) {
                row[j] = row[j] + row[j + 1];
            }
        }
        return row;
    }
};