/*
log(n - k) + k

Suppose there is a number line,

there are these numbers in the number line,

A[0],A[1],..., A[mid-1],A[mid],A[mid+1],A[mid+2], A[mid+k],...,A[n-1]

if an x meet this condition
(x - A[mid] > A[mid + k] - x),

It simply means, x is on the right side of A[mid], and it's closer to A[mid+k] than A[mid]

so we can move lo to mid+1 because

A[0],A[1],..., A[mid-1],A[mid] all these numbers will be further to x than A[mid+k],
in addition, A[mid+1], A[mid+2]....A[mid+k] will be better than A[mid]
First A[mid+k] is better than A[mid], because of (x - A[mid] > A[mid + k] - x),
then A[mid+1] is better than A[mid] because if x is in the left of A[mid+1], that 
means A[mid+1] is even closer to x than A[mid+k], if x is in the right of A[mid+1], then 
obviously A[mid+1] will be closer than A[mid],
anyway, the answer must be in the right side of mid

On the other hand, if
(x - A[mid] <= A[mid + k] - x),

means x is closer to A[mid] than A[mid + k] i.e
A[mid+k] is not in the final answer, (at lease A[mid], A[mid+1], A[mid+k-1] will be more 
eligible than A[mid+k]), i.e
A[mid+1] will be out of the search space because eventually it's lower bound of the k numbers is returned, 
here the lower bound can not be (mid+1), but it can be mid, as a result change hi to mid

i.e. A[mid], A[mid + 1], ..., A[mid + k - 1] is better than A[mid + 1], .., A[mid + k - 1], A[mid + k]
because A[mid] is better than A[mid + k]


Assume A[mid] ~ A[mid + k] is sliding window

case 1: x - A[mid] < A[mid + k] - x, need to move window go left
-------x----A[mid]-----------------A[mid + k]----------

case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
-------A[mid]----x-----------------A[mid + k]----------

case 3: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]------------------x---A[mid + k]----------

case 4: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]---------------------A[mid + k]----x------
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};