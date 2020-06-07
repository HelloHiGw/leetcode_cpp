// class Solution {
// public:
//     int mctFromLeafValues(vector<int>& arr) {
//         // maxi[i][j]: the maxVal from arr[i] to arr[j]
//         vector<vector<int>> maxi(arr.size(), vector<int>(arr.size()));
//         for (int i = 0; i < arr.size(); ++i) {
//             maxi[i][i] = arr[i];
//             for (int j = i + 1; j < arr.size(); ++j) {
//                 maxi[i][j] = max(maxi[i][j - 1], arr[j]);
//             }
//         }
//         // dp, otherwise TLE
//         vector<vector<int>> memo(arr.size(), vector<int>(arr.size()));
//         return buildMCT(0, arr.size() - 1, maxi, memo);
//     }
    
//     int buildMCT(int start, int end, vector<vector<int>>& maxi, vector<vector<int>>& memo) {
//         if (start == end) return 0;  // do not take leaf node ->val into sum
//         if (memo[start][end]) return memo[start][end];
//         int res = INT_MAX;
//         for (int i = start; i < end; ++i) {
//             // every curr is a tree
//             // index start to i denotes the leaf node in the leftSubtree
//             // index i + 1 to end denotes the leaf node in the rightSubtree
//             int curr = maxi[start][i] * maxi[i + 1][end] + buildMCT(start, i, maxi, memo) + buildMCT(i + 1, end, maxi, memo);
//             res = min(res, curr);  // res is the minimum of all the possible tree
//         }
//         return memo[start][end] = res;
//     }
// };

/*
Given an array A, choose two neighbors in the array a and b,
we can remove the smaller one min(a,b) and the cost is a * b.
What is the minimum cost to remove the whole array until only one left?
*/
// class Solution {
// public:
//     int mctFromLeafValues(vector<int>& arr) {
//         int res = 0;
//         while (arr.size() > 1) {
//             int i = 0;
//             for (int j = 1; j < arr.size(); ++j) {
//                 if (arr[j] < arr[i]) i = j;
//             }
//             if (i == 0) {
//                 res += arr[i] * arr[i + 1];
//             } else if (i == arr.size() - 1) {
//                 res += arr[i - 1] * arr[i];
//             } else {
//                 res += min(arr[i - 1], arr[i + 1]) * arr[i];
//             }
//             arr.erase(arr.begin() + i);
//         }
//         return res;
//     }
// };


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> st;
        st.push_back(INT_MAX);
        for (int a : arr) {
            while (st.back() <= a) {
                int mid = st.back();
                st.pop_back();
                res += min(st.back(), a) * mid;
            }
            st.push_back(a);
        }
        for (int i = 2; i < st.size(); ++i) {
            res += st[i] * st[i - 1];
        }
        return res;
    }
};