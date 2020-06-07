/*
Save array A to a hash set s.
Start from base (A[i], A[j]) as the first two element in the sequence,
we try to find the Fibonacci like subsequence as long as possible,

Initial (a, b) = (A[i], A[j])
While the set s contains a + b, we update (a, b) = (b, a + b).
In the end we update the longest length we find.

Time Complexity:
O(N^2logM), where M is the max(A).

Quote from @renato4:
Just clarifying a little bit more.
Since the values grow exponentially,
the amount of numbers needed to accommodate a sequence
that ends in a number M is at most log(M).
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> st(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int a = A[i], b = A[j], l = 2;
                while (st.count(a + b)) {
                    int t = a + b;
                    a = b;
                    b = t;
                    ++l;
                }
                res = max(res, l);
            }
        }
        return res < 3 ? 0 : res;
    }
};


/*
dp[i, j] represents the length of fibo sequence ends up with (A[i], A[j])
Then we have dp[a, b] = (dp[b - a, a] + 1 ) or 2
The complexity reduce to O(N^2).
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> mp; // value to index
        
        vector<vector<int>> dp(n, vector<int>(n));
        int res = 0;
        
        for (int j = 0; j < n; ++j) {
            mp[A[j]] = j;
            // try every possible combinations [i, j]
            for (int i = 0; i < j; ++i) {
                // A[j] - A[i] have to be smaller than A[i] to make a Fibonacci
                if (mp.count(A[j] - A[i]) && A[j] - A[i] < A[i]) {
                    int k = mp[A[j] - A[i]];
                    dp[i][j] = dp[k][i] + 1;  // unique answer
                } else {
                    dp[i][j] = 2;
                }
                
                res = max(res, dp[i][j]);
            }
        }
        
        return res > 2 ? res : 0;
    }
};

