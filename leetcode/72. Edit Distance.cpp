/*
  d("abbc", "acc")
= d("abb", "acc")  // last char is the same

=  1 + d("ab", "ac")   // replace b with c
or 1 + d("ab", "acc")  // delete b
or 1 + d("abb", "ac")  // insert c after abb
all the three operations are related to word1

Both String1 and String2 are empty: Then the answer to the subproblem is 0. 
Since minimum operations to be performed to make string1 as string2 is 0.

String1 is empty and String2 is not empty: We need insert characters to make it as string2. 
Minimum operations to be performed will be equal to string2 length.

String1 is not empty and String2 is empty: We have delete characters to make it as string2.

a b
a c
replace: 0 + 1 = 1, delete: 1 + 1 = 2, insert: 1 + 1 = 2, replace is better(b to c)


a b
a
replace: 1 + 1 = 2, delete: 0 + 1 = 1, insert: 2 + 1 = 3, delete is better(b to '')


a
a c
replace: 1 + 1 = 2, delete: 2 + 1 = 3, insert: 1, insert is better(add c to end)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dfs(word1, word2, word1.size(), word2.size(), memo);
    }
    
private:
    int dfs(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0 || j == 0) return i + j;  
        if (memo[i][j] != -1) return memo[i][j];
        
        if (word1[i - 1] == word2[j - 1]) {
            return memo[i][j] = dfs(word1, word2, i - 1, j - 1, memo);
        }
        
        return memo[i][j] = min({dfs(word1, word2, i - 1, j - 1, memo),  // replace
                                dfs(word1, word2, i - 1, j, memo),  // delete
                                dfs(word1, word2, i, j - 1, memo)}) + 1;  // insert
    }
};


/*
assume the following has been calculated
0.......(i-1)th
0...(j-1)th

we want dp[i][j]
0.......(i-1)th  ith
0...(j-1)th  jth

replace, dp[i][j] = dp[i - 1][j - 1] + 1 (you replace ith with jth)

delete, dp[i][j] = dp[i - 1][j] + 1 (delete word1[ith])

insert, dp[i][j] = dp[i][j - 1] + 1 (insert word2[jth] after word1[ith])

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
            
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j -  1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};
