// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> squares;
//         for (int i = sqrt(n); i >= 1; --i) {  // put bigger squares in the front, then we can get least numbers faster
//             squares.push_back(i * i);
//         }
        
//         queue<int> que;
//         vector<bool> visited(n + 1, false);  // no visted, TLE
//         for (int s : squares) {
//             que.push(s);
//             visited[s] = true;
//         }
//         int level = 0;
        
//         while (!que.empty()) {
//             ++level;
//             for (int i = que.size(); i > 0; --i) {
//                 int curr = que.front();
//                 que.pop();
//                 if (curr == n) return level;
//                 for (int s : squares) {
//                     int next = curr + s;
//                     if (next <= n && !visited[next]) {
//                         que.push(next);
//                         visited[next] = true;
//                     }
//                 }
//             }
//         }
//         return n;
//     }
// };


// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= sqrt(i); ++j) {
//                 dp[i] = min(dp[i], dp[i - j * j] + 1);
//             }
//         }
//         return dp[n];
//     }
// };


/*
Same as DP, but the array is a static variable, it persists across test cases. Any 
array values calculated during one test case will be available in future test cases 
and do not need to be recomputed.

static DP is equivalent to DP if you only call function once. However, if you call 
it several times, static vector would be reused and make whole test cases much 
faster.

Yes, for example, if you first call numSquares(100), a table with size 101 will be 
built. Then if you call numSquares(10), the function doesn't need to rebuild the 
table and it will immediately return the entry with index 10.
*/

// class Solution {
// public:
//     int numSquares(int n) {
//         static vector<int> dp = {0};
//         while (dp.size() <= n) {
//             int i = dp.size(), val = INT_MAX;
//             for (int j = 1; j <= sqrt(i); ++j) {
//                 val = min(val, dp[i - j * j] + 1);
//             }
//             dp.push_back(val);
//         }
//         return dp[n];
//     }
// };



class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        if (isSquare(n)) return 1;
        for (int i = 1; i <= sqrt(n); ++i) {
            if (isSquare(n - i * i)) return 2;
        }
        return 3;
    }

private:
    bool isSquare(int n) {
        int s = sqrt(n);
        return s * s == n;
    }
};