/*
brute force (backtracking)
time O(n!),  first n choices, second n - 1 choices ...
space O(n) 
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2.0 < desiredTotal) return false;
        vector<bool> used(maxChoosableInteger + 1, false);
        return canWin(maxChoosableInteger, desiredTotal, used);
    }
    
private:
    bool canWin(int maxD, int total, vector<bool>& used) {
        for (int i = 1; i <= maxD; ++i) {
            if (used[i]) continue;
            used[i] = true;
            if (i >= total || !canWin(maxD, total - i, used)) {  // opponent cannot win, then i win
                // carefully here, reset false, for above level visit
                // 1 2 3 total = 4, 1(A) 2(B) 3(A), if not, then B loses, cause B cannot choose 3
                used[i] = false;  
                return true;
            }
            used[i] = false;
        }
        return false;
    }
    
};


/*
The key part for the top-down dp strategy is that we need to avoid repeatedly solving sub-problems.

For this question, the key part is: what is the state of the game? Intuitively, to uniquely determine 
the result of any state, we need to know:

The unchosen numbers
The remaining desiredTotal to reach
A second thought reveals that 1) and 2) are actually related because we can always get the 2) by 
deducting the sum of chosen numbers from original desiredTotal.

Then the problem becomes how to describe the state using 1).

In my solution, I use a boolean array to denote which numbers have been chosen, and then a question 
comes to mind, if we want to use a Hashmap to remember the outcome of sub-problems, can we just use 
Map<boolean[], Boolean> ? Obviously we cannot, because the if we use boolean[] as a key, the 
reference to boolean[] won't reveal the actual content in boolean[].

Since in the problem statement, it says maxChoosableInteger will not be larger than 20, which means 
the length of our boolean[] array will be less than 20. Then we can use an Integer to represent this 
boolean[] array. How?

Say the boolean[] is {false, false, true, true, false}, then we can transfer it to an Integer with 
binary representation as 00110. Since Integer is a perfect choice to be the key of HashMap, then we 
now can "memorize" the sub-problems using Map<Integer, Boolean>.


by applying the memo, we at most compute for every subproblem once, and there are O(2^n) 
subproblems, so the complexity is O(2^n) after memorization.
the combination of key is 2^n kinds
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2.0 < desiredTotal) return false;
        vector<bool> used(maxChoosableInteger + 1, false);
        unordered_map<int, bool> memo;
        return canWin(maxChoosableInteger, desiredTotal, used, memo);
    }
    
private:
    bool canWin(int maxD, int total, vector<bool>& used, unordered_map<int, bool>& memo) {
        int key = format(used);
        if (memo.count(key)) return memo[key];
        
        bool flag = false;
        for (int i = 1; i <= maxD; ++i) {
            if (used[i]) continue;
            used[i] = true;
            if (i >= total || !canWin(maxD, total - i, used, memo)) {
                used[i] = false; 
                flag = true;
                break;
            }
            used[i] = false;
        }
        return memo[key] = flag;
    }
    
    int format(vector<bool>& used) {
        int key = 0;
        for (int i = 0; i < used.size(); ++i) {
            key = (key << 1) | used[i];
        }
        return key;
    }
};

/*
direct use int as bool array, the the ith digit is used, the ith bit of used is 1
*/

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2.0 < desiredTotal) return false;
        unordered_map<int, bool> memo;
        return canWin(maxChoosableInteger, desiredTotal, 0, memo);
    }
    
private:
    bool canWin(int maxD, int total, int used, unordered_map<int, bool>& memo) {
        if (memo.count(used)) return memo[used];
        
        bool flag = false;
        for (int i = 1; i <= maxD; ++i) {
            int mask = 1 << (i - 1);  // if i == 1, it is the first bit of used
            if (mask & used) continue;

            if (i >= total || !canWin(maxD, total - i, mask | used , memo)) {  // not reference, no need to recover
                flag = true;
                break;
            }
        }
        return memo[used] = flag;
    }
};