/*
For each element, either 1 or 2
1. It could append to an existing subsequence 
2. It could be the start of a new subsequence. 
Otherwise, return false.
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // need[i] subsequence can continue from i
        unordered_map<int, int> freq, need;
        for (int num : nums) ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) continue;
            if (need[num]) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] && freq[num + 2]) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else {
                return false;
            }
            --freq[num];
        }
        return true;
    }
};

/*
eg: [1,2,3,4, 5]
// i =1
we fall in case 2 "start of a new subsequence"
we make 2, 3 freq 0
and put <4, 1> in need, this mean I have 1 subsequence can continue from 4

//i =2, 3
we continue

//i = 4
we fall in case 1, since 4 is in need
now this subsequence should end in 5
so we decreace <4, 1> to <4, 0> since we no longer have subsequence can continue from 4
and we put <5, 1> in need since now we have a subsequence can continue from 5


In my algorithm, I first check whether nums[i] can create a new subsequence; if not, 
then check whether it can extend existing subsequences.
But it passed 178/180 test cases, can anyone tell me where was wrong? Thank you!

Consider this case: 1 2 3 4 5 5 6 7. If you create a new subsequence first you will 
get 1 2 3 then 4 5 6 then return false. But actually the answer is true because we can 
split the array by 1 2 3 4 5 and 5 6 7.

here shows greedy
*/