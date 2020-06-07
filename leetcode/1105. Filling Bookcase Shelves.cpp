/*
hard to find the transition

dp[i]: the min height for placing first i books  on shelves

For dp[i],
either place book i on a new shelve => dp[i] = dp[i - 1] + height[ith],
or grab previous books(jth book to (i-1)th book) together with book i and move to next 
level together, utlitzing  the sub problem dp[j - 1] => min(dp[j - 1] + max(height[jth] .. height[ith])), where sum(width[jth] + ... + sum(width[ith]) <= shelve_width


The key idea of this algorithm goes as follows

1 Start placing books one by one, always use a new shelve to begin with

2 After you stored the new height value at this position in your dp array, start looking 
back at previous books one by one, and see while the width permits, how many books you 
can fit on this new level.

3 Check to see if bringing said books down reduced the overall height, if it did, update 
the new loest height value at your dp array.

4 return the last element of your dp array


when it comes for 7
1
2     3
4 5 6
7

1
2     3
4 5 
6 7

1
2     3
4  
5 6 7

1
2     3
4 5 6 7
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int height = books[i - 1][1];
            int width = books[i - 1][0];
            dp[i] = dp[i - 1] + height;
            
            for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelf_width; --j) {
                height = max(height, books[j - 1][1]);
                width += books[j - 1][0];
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        
        return dp[n];
    }
};