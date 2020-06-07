/*
O(n ^ 2) TLE
constraint n = 1e5
34 / 38 test cases passed.

dp[i] = 
1,                   no arr[i] - d
dp[arr[i] - d] + 1,  arr[i] - d exists
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // dp[i] length of Arithmetic Subsequence ending with arr[i]
        vector<int> dp(n);
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;  // boundary
            for (int j = i - 1; j >= 0; --j) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = dp[j] + 1;
                    // you can break here, no need use dp[i] = max(dp[i], dp[j] + 1)
                    // e.g. 1 3 5 3 5 difference = 2,
                    // dp[4] = dp[3] + 1 = dp[0] + 1 + 1 = 3
                    // if the first 3 can find a 1, the second 3 can always find a 1
                    break;
                }
            }
            res = max(res, dp[i]);
        }
        
        return res;
    }
};


/*
let's say why the above can get TLE
it is because of the second loop, we use another loop to find whether there
is a arr[j] satifying arr[i] - diffrence = arr[j], it is O(n)

we can  sacrifice space to improve efficiency

use unordered_map<int, int> mp to replace dp
mp[i] = len means Arithmetic Subsequence ending with arr[i] is length of len

so when meets arr[i], we can retrieve arr[i] - difference and get the len of 
Arithmetic Subsequence ending with arr[i] - differene in O(1)

if we meet a number which is already a key in mp
e.g. 3 5 1 3 5 the second 3
we can cover the original 3 with the new 3
because the Arithmetic Subsequence ending with the new 3 is always equal or bigger 
than the old 3
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            int curr = 1;
            int prev = arr[i] - difference;
            if (mp.count(prev)) curr = mp[prev] + 1;
            mp[arr[i]] = curr;
            res = max(res, curr);
        }
        
        return res;
    }
};
