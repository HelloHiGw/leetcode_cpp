// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         int res = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             dp[i] = 1;
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for (int num : nums) {
            int insertPos = lowerBound(tail, num);
            if (insertPos == tail.size()) {
                tail.push_back(num);
            } else {
                tail[insertPos] = num;
            }
        }
        return tail.size();
    }
    
    int lowerBound(vector<int> &v, int target) {
        int low = 0, high = v.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (v[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};



/*
detailed explanation for (especially the example)
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/


10 9 2 5 3 7 101 18

we maintain the smallest sequence of every possible len (from length 1 to length maxLen), smallest is for adding relatively small number for generating longer sequence afterwards.

we need to maintain lists of increasing sequences
So the main idea is:
Use binary search to either
-- extend increasing sequence with larger numbers, or
-- minimize existing values with smaller ones - so we can use smaller numbers to extend it.

10

9 (10 is replaced by 9, so when 10 comes afterwards, we can have 9 10)

2 (9 is replaced by 2, the same, when 3 comes afterwards, we can have 2 3)

2
2 5 (the smallest sequence for every possivel length)

2
2 3 (2 5 is replaced by 2 3)

2
2 3
2 3 7 (len++)

2 
2 3
2 3 7
2 3 7 101 (len++)

2
2 3
2 3 7
2 3 7 18 (2 3 4 101 is replaced by 2 3 7 18, which is the answer)

Note that we are dealing with end elements only. We need not to maintain all the lists. 
We can store the end elements in an array. Discarding operation can be simulated with
replacement, and extending a list is analogous to adding more elements to array.
e.g [2, 3, 7, 18] (the ending element from smaller len to larget len is increasing)

[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
*/