/*
Edge case 1: all three stones are next to each other (z - x == 2). Return {0, 0}.
Edge case 2: two stones are next to each other, or there is only one space in between. 
Minimum moves is 1.

Otherwise; minimum moves are 2, maximum - z - x - 2.

So the position of the middle stone (y) only matters for the minimum moves.
*/
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        
        if (c - a == 2) return {0,  0};
        int space1 = b - a - 1;
        int space2 = c - b - 1;
        int mn = min(space1, space2);
        // space1 + space2 = c - a - 2
        return {mn <= 1 ? 1 : 2, space1 + space2};
    }
};