// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& A, int K) {
//         sort(A.begin(), A.end());
//         int sum = 0;
//         int minAbsIndex = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             if (K) {
//                 if (abs(A[i]) < abs(A[minAbsIndex])) minAbsIndex = i;
//                 if (A[i] < 0) {
//                     A[i] = -A[i];
//                     --K;
//                 } else {
//                     if (K % 2 == 1) {
//                         A[minAbsIndex] = -A[minAbsIndex];
//                         if (minAbsIndex != i) sum += 2 * A[minAbsIndex];
//                     }
//                     K = 0;
//                 }
//             }
//             sum += A[i];
//         }
//         return sum;
//     }
// };


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() && A[i] < 0 && K; ++i) {
            A[i] = -A[i];
            --K;
        }
        return accumulate(A.begin(), A.end(), 0) - (K % 2 == 1) * 2 * (*min_element(A.begin(), A.end()));
    }
};