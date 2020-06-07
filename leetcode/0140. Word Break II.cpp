class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<string>> memo(s.size() + 1);
        memo[s.size()] = {""};
        return dfs(0, s, words, memo);
    }

private:
    vector<string> dfs(int i, string& s, unordered_set<string>& words, vector<vector<string>>& memo) {
        if (!memo[i].empty()) return memo[i]; 
        // this is not a good memo
        // because you can not judge memo[i].empty() denotes what
        // if can be uncalculated, or be no answer
        // if it is no answer, you again calculate it mutiple times, TLE
        vector<string> curr;
        for (int j = i; j < s.size(); ++j) {
            string word = s.substr(i, j - i + 1);
            if (!words.count(word)) continue;

            vector<string> subList = dfs(j + 1, s, words, memo);
            for (string& sub : subList) {
                curr.push_back(word + (sub.empty() ? "" : " ") + sub);
            }
        }

        return memo[i] = curr;
    }
};


/*
catandcatandcat ["cat", "and"]
memo["cat"] = {"cat"};
memo["andcat"] = {"and cat"}
memo["catandcat"] = {"cat and cat"}

the key of memo is definitately different, so ok for the same cat
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;  //memo[s] answer of string s
        memo[""] = {""}; // leaf node
        return dfs(s, words, memo);
        
    }

private:
    vector<string> dfs(string s, unordered_set<string>& words, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) return memo[s];
        // memo.count(s) denotes s has been calculated, is no answer, memo[s] = {}
        vector<string> curr;
        for (int i = 0; i < s.size(); ++i) {
            string word = s.substr(0, i + 1);
            if (!words.count(word)) continue;
            
            vector<string> subList = dfs(s.substr(i + 1), words, memo);
            for (string& sub : subList) {  // if subList is empty, will not concatenate word
                curr.push_back(word + (sub.empty() ? "" : " ") + sub);
            }
        }

        return memo[s] = curr;
    }
};

/*
why iterative method (dp) gets TLE ? 
it's time complexity is O(n ^ 2), dfs + memo definitely smaller than O(n ^ 2)

"abcedfghijklmnopqrsuvwxyz"  ["cat", "dog"]
dfs + memo is O(n)
bottom-up dp is O(n ^ 2)
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;  //memo[s] answer of string s
        memo[""] = {""}; // leaf node
        
        for (int i = s.size() - 1; i >= 0; --i) {
            vector<string> curr;
            for (int j = i; j < s.size(); ++j) {
                string word = str.substr(i, j - i + 1);
                if (!words.count(word)) continue;

                vector<string> subList = memo[str.substr(j + 1)];
                for (string& sub : subList) {
                    curr.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
            
            memo[s.substr(i)] = curr;
        }
        
        return memo[s];
    }
};
