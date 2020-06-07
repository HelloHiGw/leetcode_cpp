class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] till the ith house
        // dp[i][0] the max robbing value till the ith hourse (not rob ith hourse)
        // d[i][1] the max robbing value till the ith hourse (rob ith hourse)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);  // here is max(dp[i-1])
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        
        return max(dp[n][0], dp[n][1]);
    }

};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int skip = 0, take = 0;
        for (int i = 0; i < n; ++i) {
            int skipi = max(skip, take);
            int takei = skip + nums[i];
            skip = skipi;
            take = takei;
        }

        return max(skip, take);
    }
};

/*
the following two are not good as above two

there are more boundary judgement
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        // even if malloc 1 more space, but i need dp[i - 2]
        // so still to one special judgement dp[1]
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);  // dp[i], the max robbing value till the ith hourse
        dp[1] = nums[0];
        
        for (int i = 2; i <= n; ++i) {
            // do not rob i         rob i (means rob i - 2 at the same)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int prev2 = 0, prev = nums[0];
        
        for (int i = 2; i <= n; ++i) {
            int curr = max(prev, prev2 + nums[i - 1]);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};