// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res;
//         for (int k = 0; k <= nums.size(); ++k) {
//             vector<int> curr;
//             backtrack(k, 0, nums, curr, res);
//         }
//         return res;
//     }
    
//     void backtrack(int k, int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
//         if (k == 0) {
//             res.push_back(curr);
//             return;
//         }
//         if (start + k - 1 >= nums.size()) return;  // not enough k nums left
//         for (int i = start; i < nums.size(); ++i) {
//             curr.push_back(nums[i]);
//             backtrack(k - 1, i + 1, nums, curr, res);
//             curr.pop_back();
//         }
//     }
// };

// 666
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, nums, curr, res);
        return res;
    }
    
    void backtrack(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }
};

/*
order:
[] [1] [1 2] [1 2 3] [1 3]
[2] [2 3]
[3]
        
                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []
*/