/*
swap[i] means the minimum swaps to make the A[0,i] and B[0, i] sequences increasing 
if we swap A[i] and B[i]

notSwap[i] means the minimum swaps to make the A[0,i] and B[0, i] sequences 
increasing if we DO NOT swap A[i] and B[i]

A[i - 1] < A[i] && B[i - 1] < B[i].
In this case, if we want to keep A and B increasing, can only have two choices.
-> 1.1 don't swap at (i-1) and don't swap at i, we can get not_swap[i] = not_swap[i-1]
-> 1.2 swap at (i-1) and swap at i, we can get swap[i] = swap[i-1]+1
if swap at (i-1) and do not swap at i, we can not guarantee A and B increasing.

A[i-1] < B[i] && B[i-1] < A[i]
In this case, if we want to keep A and B increasing, can only have two choices.
-> 2.1 swap at (i-1) and do not swap at i, we can get notswap[i] = Math.min(swap[i-1], notswap[i] )
-> 2.2 do not swap at (i-1) and swap at i, we can get swap[i]=Math.min(notswap[i-1]+1, swap[i])
*/
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> swap(n), notSwap(n);
        notSwap[0] = 0;
        swap[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            notSwap[i] = swap[i] = INT_MAX / 2;
            // the followint two for loops, at least one is established
            // one or both
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                notSwap[i] = notSwap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                notSwap[i] = min(notSwap[i], swap[i - 1]);
                swap[i] = min(swap[i], notSwap[i - 1] + 1);
            }
        }
        
        return min(notSwap[n - 1], swap[n - 1]);
    }
};

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int notSwap = 0, swap = 1;
        
        for (int i = 1; i < n; ++i) {
            int notSwapi = INT_MAX / 2, swapi = INT_MAX / 2;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                notSwapi = notSwap;
                swapi = swap + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                notSwapi = min(notSwapi, swap);
                swapi = min(swapi, notSwap + 1);
            }
            notSwap = notSwapi;
            swap = swapi;
        }
        
        return min(notSwap, swap);
    }
};