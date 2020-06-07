class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<vector<int>>> mp;
        for (int i = 0; i < groupSizes.size(); ++i) {
            int num = groupSizes[i];
            if (!mp.count(num) || mp[num].back().size() == num) {
                mp[num].push_back({i});
            } else {
                mp[num].back().push_back(i);
            }
        }
        
        vector<vector<int>> res;
        for (auto& it : mp) {
            res.insert(res.end(), it.second.begin(), it.second.end());
        }
        
        return res;
    }
};