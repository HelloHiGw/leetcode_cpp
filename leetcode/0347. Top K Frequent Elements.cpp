// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for (int num : nums) ++mp[num];
    
//         sort(nums.begin(), nums.end(), [&](int a, int b){
//             if (mp[a] != mp[b]) return mp[a] > mp[b];
//             return a < b;
//         });
        
//         vector<int> res;
//         for (int i = 0; i < nums.size() && res.size() < k; ++i) {
//             if (i && nums[i] == nums[i - 1]) continue;
//             res.push_back(nums[i]);
//         }
        
//         return res;
//     }
// };

/*
O(n) buckets sort
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) ++mp[num];
    
        vector<vector<int>> buckets(n + 1);  // max freq is at most n
        for (auto& it : mp) {
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> res;
        for (int i = n; i > 0 && res.size() < k; --i) {
            if (buckets[i].empty()) continue;
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            if (res.size() > k) {
                res.erase(res.begin() + k, res.end());
            }
        }
        
        return res;
    }
};