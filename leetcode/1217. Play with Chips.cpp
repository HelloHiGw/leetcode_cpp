class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int oddCount = 0, evenCount = 0;
        for (int pos : chips) {
            if (pos % 2 == 0) {
                ++evenCount;
            } else {
                ++oddCount;
            }
        }
        return min(oddCount, evenCount);
    }
};