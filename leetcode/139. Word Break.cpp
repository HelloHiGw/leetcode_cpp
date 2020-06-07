/*
normal dfs TLE
it is not backtracking, in backtracking, there is select i or not select i
here you must select i

dfs + memo

time O(n ^ 2) (worst)
in essence, the states is smaller than n

catanddog ["cat", "and", "dog"]
there are only 3 states (catanddog, anddog, dog)


space O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        memo[""] = true;
        return dfs(s, words, memo);
    }
    
private:
    bool dfs(string& s, unordered_set<string>& words, unordered_map<string, bool>& memo) {
        // cannot use vector<bool> dp
        // because you can not distinguish not computed and answer false with dp[i]
        // also you can use unordered_map<int, bool>, it is the same idea as current memo
        if (memo.count(s)) return memo[s];
        
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            string word = s.substr(0, i + 1);
            if (!words.count(word)) continue;
            
            string next = s.substr(i + 1);
            if (dfs(next, words, memo)) {
                flag = true;
                break;
            }
        }
        return memo[s] = flag;
    }
};



/*
time O(n ^ 2)
the state is n (the first loop), worse than dfs + memo

"abcedfghijklmnopqrsuvwxyz"  ["cat", "dog"]
dfs + memo is O(n)
bottom-up dp is O(n ^ 2)

space O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> dp;
        dp[""] = true;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            bool flag = false;
            
            for (int j = i; j < s.size(); ++j) {
                string word = s.substr(i, j - i + 1);
                if (!words.count(word)) continue;
                
                string next = s.substr(j + 1);
                if (dp[next]) {
                    flag = true;
                    break;
                }
            }
            
            dp[s.substr(i)] = flag;
        }
        
        return dp[s];
    }
};


