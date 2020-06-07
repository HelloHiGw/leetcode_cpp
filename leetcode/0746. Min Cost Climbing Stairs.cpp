class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre1 = cost[0], pre2 = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int temp = min(pre1, pre2) + cost[i];
            pre1 = pre2;
            pre2 = temp;
        }
        return min(pre1, pre2);
    }
};