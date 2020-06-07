class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> row;
        for (int i = 1; i <= numRows; ++i) {
            row.insert(row.begin(), 1);
            for (int j = 1; j < i - 1; ++j) {
                row[j] = row[j] + row[j + 1];
            }
            v.push_back(row);
        }
        return v;
    }
};