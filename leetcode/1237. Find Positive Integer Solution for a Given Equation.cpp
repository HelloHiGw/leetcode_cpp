/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

/*
x * log(y)
*/
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& fun, int z) {
        vector<vector<int>> res;
        for (int x = 1; x <= 1000; ++x) {
            int left = 1, right = 1000, mid;
            int ans;
            
            while (left <= right) {
                mid = left + (right - left) / 2;
                ans = fun.f(x, mid);
                if (ans == z) {  // found
                    res.push_back({x, mid});
                    break;
                } else if (ans > z) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // not found
        }
        return res;
    }
};

/*
In binary search,
time complexity is O(XlogY) or O(YlogX)

In this solution,
time complexity is stable O(X + Y).

Bianry search is really an unnecessay operation,
and it won't help improve the complexity at all.

strictly increasing for x or y
f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
*/
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& fun, int z) {
        vector<vector<int>> res;
        int x = 1, y = 1000;
        while (x <= 1000 && y >= 1) {
            int val = fun.f(x, y);
            if (val == z) {
                res.push_back({x, y});
                ++x;
                --y;
            } else if (val < z) {
                ++x;
            } else {
                --y;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& fun, int z) {
        vector<vector<int>> res;
        int y = 1000;
        for (int x = 1; x <= 1000; ++x) {
            while (y > 1 && fun.f(x, y) > z) --y;
            if (fun.f(x, y) == z) {
                res.push_back({x, y});
            }
        }
        return res;
    }
};