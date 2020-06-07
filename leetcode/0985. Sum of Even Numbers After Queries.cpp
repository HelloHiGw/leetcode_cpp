class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        int sum = 0;
        for (int num : A) {
            sum += num % 2 == 0 ? num : 0;
        }
        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][0], idx = queries[i][1];
            if (A[idx] % 2 == 0) sum -= A[idx];
            A[idx] += val;
            if (A[idx] % 2 == 0) sum += A[idx]; 
            res[i] = sum;
        }
        return res;
    }
};