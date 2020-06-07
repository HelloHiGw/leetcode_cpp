// // 70 / 83 test cases passed. TLE O(n^3)
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         unordered_set<int> st;
//         for (int i = 0; i < A.size(); ++i) {
//             for (int j = i; j < A.size(); ++j) {
//                 int x = 0;
//                 for (int t = i; t <= j; ++t) x |= A[t];
//                 st.insert(x);
//             }
//         }
//         return st.size();
//     }
// };


// // 72 / 83 test cases passed. TLE O(n^2)
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, 0));  // dp[i][j] denotes the or value from ith char to jth char
//         unordered_set<int> st;
//         for (int i = 1; i <= A.size(); ++i) {
//             for (int j = i; j <= A.size(); ++j) {
//                 dp[i][j] = dp[i][j - 1] | A[j - 1];
//                 st.insert(dp[i][j]);
//             }
//         }
//         return st.size();
//     }
// };


// 72 / 83 test cases passed. TLE O(n^2)
// rolling array
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         vector<int> dp(A.size() + 1, 0);
//         unordered_set<int> st;
//         for (int i = 1; i <= A.size(); ++i) {
//             dp[i - 1] = 0;
//             for (int j = i; j <= A.size(); ++j) {
//                 dp[j] = dp[j - 1] | A[j - 1];
//                 st.insert(dp[j]);
//             }
//         }
//         return st.size();
//     }
// };

/*
dp[i] := {A[i], A[i] | A[i – 1], A[i] | A[i – 1] | A[i – 2], … , A[i] | A[i – 1] | … | A[0]}, 
bitwise ors of all subarrays end with A[i].
dp[i] = A[i] | element (for each element in dp[i - 1])

|dp[i]| <= 32
Proof: all the elements (in the order of above sequence) in dp[i] are monotonically increasing 
by flipping 0 bits to 1 from A[i].
There are at most 32 0s in A[i]. Thus the size of the set is <= 32.

in method 3, there are many duplicates in vector dp[], the TC is O(n^2)
so we use unordered_set to repalce with vector

TC < O(32 * N)
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> curr;
        unordered_set<int> pre;
        unordered_set<int> res;
        for (int a : A) {
            curr.clear();
            curr.insert(a);
            for (int b : pre) {  // O(pre.size()) < O(32)
                curr.insert(a | b);
            }
            res.insert(curr.begin(), curr.end()); // O(curr.size()) < O(32)
            swap(pre, curr);
        }
        return res.size();
    }
};