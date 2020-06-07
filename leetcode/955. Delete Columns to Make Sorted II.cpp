/*
sorted[j] denotes whether A[j] is strictly bigger than A[j - 1]

假设输入是["xgag","xfba","yfac"]
那么第一轮i=0,比较第一列: x=x<y，合理，所以此时res=0，然后运行了下面的循环， 可以使得sorted[2] = true;
然后第二轮i=1,第二列g>f,进入if条件语句，所以res = 1, break
然后第三轮i=2,a<b>a,这里b虽然>a，但是由于sorted[2] = true，所以不会进入到上面的循环体，然后sorted[1] = true
然后第四轮j=3,这一轮已经不再重要，因为通过前面几轮 sorted[1] = true， sorted[2] = true, 这意味着已经实现了排序，
所以res最终结果就是1

time O(n * L)
space O(n)
*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), len = A[0].size();
        int res = 0;
        vector<bool> sorted(n, false);
        
        for (int i = 0; i < len; ++i) {
            int j;
            for (j = 1; j < n; ++j) {
                // if A[j] is strictly bigger than A[j - 1], no need comparing
                if (!sorted[j] && A[j][i] < A[j - 1][i]) {
                    ++res;
                    break;
                }
            }
            
            if (j == n) {
                // cannot update when A[j][i] > A[j - 1][i]
                // because it is probably a deleted column afterwards
                // if it is deleted, you cannot take it into account
                for (j = 1; j < n; ++j) {
                    if (A[j][i] > A[j - 1][i]) sorted[j] = true;
                }
            }
        }
        return res;
    }
};