class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minVal = *min_element(A.begin(), A.end());
        int maxVal = *max_element(A.begin(), A.end());
        
        if (maxVal - minVal <= 2 * K) return 0;
        return maxVal - minVal - 2 * K;
    }
};