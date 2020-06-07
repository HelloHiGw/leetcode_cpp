class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size());
        for (int i = 0; i < A.size(); ++i) {
            int currMax = 0;  // A[i] >= 0
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                currMax = max(currMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + currMax * k);
            }
        }
        return dp.back();
    }
};

/*
dp[i] record the maximum sum we can get considering A[0] ~ A[i]
To get dp[i], we will try to change k last numbers separately to the maximum of them,
where k = 1 to k = K.   A[i] to A[i - K + 1];


the rudiment for loop is 
for (int k = 1; k <= K; ++k) {
    currMax = max(currMax, A[i - k + 1]);
    dp[i] = max(dp[i], dp[i - k] + currMax * k);
}

then you add boundary judgement
*/