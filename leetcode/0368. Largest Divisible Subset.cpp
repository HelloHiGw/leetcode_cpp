/*
totally the same as LIS, O(n ^ 2)
but due to vector.push_back(), it runs slowly
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // we want set, the relative order in the set does not matter
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n);
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]};  // boundary, same as LIS
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size()) {  // transition, same as LIS
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
            if (dp[i].size() > res.size()) res = dp[i];
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> count(n, 0), prev(n, -1);
        int maxLen = 0, maxIndex = -1;
        
        for (int i = 0; i < n; ++i) {
            count[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && count[j] + 1 > count[i]) {
                    count[i] = count[j] + 1;
                    prev[i] = j;
                }
            }
            
            if (count[i] > maxLen) {
                maxLen = count[i];
                maxIndex = i;
            }
        }
        
        vector<int> res;
        for (int i = 0; i < maxLen; ++i) {
            res.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        // // or
        // while (maxIndex != -1) {
        //     res.push_back(nums[maxIndex]);
        //     maxIndex = prev[maxIndex];
        // }
        
        return res;
    }
};