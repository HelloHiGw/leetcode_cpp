/*
@xuefei1 I have read comments from both @luofei and @zipte89, but I still could not get it. 
Then, I thought a prove like below:

If the mid variable converges to an integer, a_mid, which is not the kth smallest element, a_k, 
in the array.
Then, a_mid should be bigger than a_k, if not the count will be less than k and a_mid will 
increase.
Therefore, lo<=a_k<a_mid<=hi will be true, and the loop ends at lo=hi, which means a_mid has to 
equal to a_k.

Looks like a squeeze theorem.

Adding on to @luofei 's answer. The element found by this algorithm has to be in the input 
matrix because the range converges to the minimum value that satisfies (or most closely 
follows) the condition count == k. The first value to satisfy count == k must be found in the 
range if exists.

The reason why we did not use index as "search space" for this problem is the matrix is sorted 
in two directions, we can not find a linear way to map the number and its index.

min-max binary search O(log(max - min) * n ^ 2)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int j = n - 1;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) --j;
                count += j + 1;
            }
            // fint the first number, which count of number smaller or equal in matrix is k
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};