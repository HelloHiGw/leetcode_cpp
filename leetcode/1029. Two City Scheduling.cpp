class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort(costs.begin(), costs.end(), cmp);
        nth_element(costs.begin(), costs.begin() + costs.size() / 2, costs.end(), cmp);
        int res = 0;
        for (int i = 0; i < costs.size() / 2; ++i) {
            res += costs[i][0] + costs[i + costs.size() / 2][1];
        }
        return res;
    }
    
private:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[1] - v1[0] > v2[1] - v2[0];
    }
};

/*
try to make it much easier to understand.
let's say two person, v1 and v2, if v1[1] - v1[0] > v2[1] - v2[0], it equals to 
v1[0] + v2[1] < v1[1] + v2[0], which means v1 to A and v2 to B is cheaper than 
vice verse.

niu!
*/
