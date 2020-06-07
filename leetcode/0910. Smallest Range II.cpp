/*
the basic idea should be the left part + K and the right part - K
there may generate the optimal answer

because all element + K will not affect the relative difference
that becomes left part + 2 * K and right part + 0

and we want find a best segment point(between left(+2K) and right(+0))

*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int mx = A.back(), mn = A[0];
        int res = mx - mn;
        
        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, A[i] + 2 * K);
            // element after i + 1 are bigger than A[i + 1]
            // element in [1, i] are bigger than A[0] + 2 * k
            mn = min(A[i + 1], A[0] + 2 * K);
            res = min(res, mx - mn);
        }
        
        return res;
    }
};