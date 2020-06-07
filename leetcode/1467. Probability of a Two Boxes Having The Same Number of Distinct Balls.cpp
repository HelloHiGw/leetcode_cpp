/*
First, compute the total number of distinct shuffles.

total = factorial(sum( A[i] | 0 <= i < k )) / (factorial(A[0]) * factorial(A[1]) * ... * 
factorial(A[k-1]))
where factorial(x) is the number of permutations of x different items. For example, 
factorial(3) = 1 * 2 * 3 = 6.

I denote the right-hand side of the above equation as perm(A) where A is an array of 
numbers. We'll need it later.

Then we need to compute the count of valid splits. Assume array a and b is a split of A, then:

size(a) == size(b) == size(A) == k
For each 0 <= i < k, a[i] + b[i] = A[i]
For example, if A = [1, 2, 2], then a = [1, 0, 1], b = [0, 2, 1] is a split of A.

A split is valid if:

Each of them contains half of the balls: sum( a[i] | 0 <= i < k ) == sum( b[i] | 0 <= i 
< k ) == sum( A[i] | 0 <= i < k ) / 2
They contain equal number of distinct colors: count(a) == count(b) where count(x) is the 
number of positive numbers in array x.
For example, if A = [1, 1, 2], then a = [1, 0, 1], b = [0, 1, 1] is a valid split of A.

So we can use DFS to get different valid splits of A. For each valid split a, b, the count of distinct permutation of the split is perm(a) * perm(b) .

The answer is the sum of perm(a) * perm(b) of all valid splits a, b divided by total.

n = balls.size() max = *max_element(balls)

time O((max + 1) ^ n * sum(balls))
O((max + 1) ^ n) states(leaf node)
at leaf node, find unique is O(n), calculate perm is O(sum(balls))

space O(n)

I think the complexity should be O(7^8 * 8 * 6) and not O(7^8 * 8) because 7^8 times you are reaching to 
the leaf node and there you are doing two things. One is to find the count of > 0 numbers which will take 
O(8) and then you are calculating perm(a) and perm(b) which together should take O(8*6) as your perm() 
inner loop will run this many number of times in total. 
*/
class Solution {
public:
    double getProbability(vector<int>& balls) {
        sum = accumulate(balls.begin(), balls.end(), 0);
        vector<int> a(balls.size()), b(balls.size());
        double valid = dfs(balls, a, b, 0, 0, 0);
        double total = perm(balls);
        return valid / total;
    }
    
private:
    int sum;
    
    // this function is really great, it avoid overflowing
    // by computing numerator and denominator at the same time
    double perm(vector<int>& v) {
        double res = 1;
        for (int i = 0, j = 1; i < v.size(); ++i) {
            int n = v[i];
            for (int k = 1; k <= n; ++k, ++j) {
                res = res * j / k;
            }
        }
        return res;
    }
    
    double dfs(vector<int>& balls, vector<int>& a, vector<int>& b, int i, int sumA, int sumB) {
        if (sumA > sum / 2 || sumB > sum / 2) return 0;
        if (i == balls.size()) {
            int uniqueA = 0, uniqueB = 0;
            for (int j = 0; j < balls.size(); ++j) {
                uniqueA += a[j] > 0;
                uniqueB += b[j] > 0;
            }
            if (uniqueA != uniqueB) return 0;
            return perm(a) * perm(b);
        }
        double res = 0;
        for (int cnt = 0; cnt <= balls[i]; ++cnt) {
            a[i] = cnt;
            b[i] = balls[i] - cnt;
            res += dfs(balls, a, b, i + 1, sumA + a[i], sumB + b[i]);
        }
        // recover
        a[i] = b[i] = 0;
        return res;
    }
};