class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // find the first pos, which A[pos] > A[pos + 1]
        // set low = 0, high = A.size() - 1 or high = A.size() also can pass
        int low = 1, high = A.size() - 2;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] > A[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};