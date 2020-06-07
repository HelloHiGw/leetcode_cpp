class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0, nextEnd = 0;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) { 
            nextEnd = max(nextEnd, nums[i] + i);
            if (i == end) {
                end = nextEnd;
                ++res;
                if (end >= n - 1) break;  // early stop
            }
        }
        return res;
    }
};
/*
This is an implicit bfs solution. i == end means you visited all the items on the 
current level. Incrementing res++ is like incrementing the level you are on. And end = 
nextEnd is like getting the queue size (level size) for the next level you are 
traversing.

You can assume that you can always reach the last index.
so there is no if (i > end) return -1;
*/