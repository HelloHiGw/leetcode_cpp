class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn = 1e4 + 1;
        vector<int> buckets(maxn, 0);
        for (int num : nums) {
            buckets[num] += num;
        }
        
        int prev2 = 0, prev = buckets[1];
        for (int i = 2; i < maxn; ++i) {
            int curr = max(prev2 + buckets[i], prev);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn = 1e4 + 1;
        vector<int> buckets(maxn, 0);
        for (int num : nums) {
            buckets[num] += num;
        }
        
        int skip = 0, take = 0;
        for (int i = 1; i < maxn; ++i) {
            int skipi = max(skip, take);
            int takei = skip + buckets[i];
            skip = skipi;
            take = takei;
        }
        
        return max(skip, take);
    }
};