class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> st(candies.begin(), candies.end());
        if (st.size() >= candies.size() / 2) return candies.size() / 2;
        return st.size();
    }
};