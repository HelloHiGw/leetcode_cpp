/*
In the above code. dp is the data structure storing all promising current states. A state 
here refers to a key-value pair, whose first element is the number we choose for current 
position. This can be either chosen from the original arr1 or from a replacement action from 
arr2. The second element is how many times we change the number. 

In the outer iteration, each time we first pick up the original element in arr1 as i. Then we 
look up in dp, trying to prolong each valid state we generated from the previous iteration. 

For example, we have state (5,0), and now i=7, we say um, it looks good so far we can generate a 
new state (7,0) because 7>5 it is increasing. No need to pick up a number from arr2. 

Meanwhile, another road is to choose a number from arr2 to replace 7. This number should be 
slightly bigger than 5. We choose the minimum number in arr2 that is bigger than 5, say 6. We can 
also add state (6,1) to dp. 

When both roads die, we can claim that the previous state can not be extended in this round. 
After we finish the final round, we look up into dp to see who survived the procedure and choose the minimum change one

1 5 3 6 7  st {1, 3, 4}
we do not need duplicates in arr2, and st.upper_bound is faster than sorted array

val = 1, dp = {{-1, 0}}
temp = {{1, 0}} 
if we replace 1 with upper_bound(-1), state is {1, 0 + 1} is bigger than {1, 0}
which will never be the optimal answer

val = 5, dp = {{1, 0}}
temp = {{5, 0}, {3, 1}}

val = 3, dp = {{5, 0}, {3, 1}}
temp = {{4, 2}}

val = 6, dp = {{4, 2}}
temp = {{6, 2}}

val = 7, dp = {{6, 2}}
temp = {{7, 2}}


time O(mlogm + n * n * logm)
the second n is dp.size(), it is directly proportional to n

space O(m + n)

there seems to be better answer O(m * n) in discussion
*/
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> st(arr2.begin(), arr2.end());
        int n = arr1.size();
        unordered_map<int, int> dp, temp;
        dp[-1] = 0;
        
        for (int val : arr1) {
            temp.clear();
            
            for (auto& d : dp) {
                // if we do not need change
                if (val > d.first) {
                    int lastCount = temp.count(val) ? temp[val] : INT_MAX;
                    temp[val] = min(d.second, lastCount);
                }
                // if we choose an element in arr2 to replace current val
                auto iter = st.upper_bound(d.first);
                if (iter != st.end()) {
                    int newVal = *iter;
                    int lastCount = temp.count(newVal) ? temp[newVal] : INT_MAX;
                    temp[newVal] = min(d.second + 1, lastCount);
                }
            }
            
            dp = temp;
            if (dp.empty()) return -1; // early stop
        }
        
        int res = INT_MAX;
        for (auto& d : dp) {
            res = min(res, d.second);
        }
        return res;
    }
};

