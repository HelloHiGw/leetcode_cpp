/*
time two pass
space O(1)
*/
class Solution {
public:
    int maxScore(string s) {
        int numOnes = 0, numZeros = s[0] == '0';
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i] == '1') ++numOnes;
        }
        
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            res = max(res, numZeros + numOnes);
            s[i] == '0' ? ++numZeros : --numOnes;
        }
        
        return res;
    }
};

/*
Max( zeroL + oneR )
= Max( zeroL - oneL + oneL + oneR )
= Max( zeroL - oneL ) + oneTotal

time one pass
space O(1)
*/


class Solution {
public:
    int maxScore(string s) {
        int numOnes = 0, numZeros = 0;
        int n = s.size();
        int res = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            s[i] == '0' ? ++numZeros : ++numOnes;
            if (i < n - 1) res = max(res, numZeros - numOnes);
        }
        
        return res + numOnes;
    }
};