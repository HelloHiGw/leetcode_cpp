class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxValue = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size());
        
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxValue) res[i] = true;
        }
        
        return res;
    }
};