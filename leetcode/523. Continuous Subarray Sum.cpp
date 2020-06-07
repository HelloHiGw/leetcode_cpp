/*
(a+(n*x))%x is same as (a%x)

For e.g. in case of the array [23,2,6,4,7] the running sum is [23,25,31,35,42] and the remainders 
are [5,1,1,5,0]. We got remainder 5 at index 0 and at index 3. That means, in between these two 
indexes we must have added a number which is multiple of the k. Hope this clarifies your doubt :)

i.e. if we gets two same remainder (except 0, remainder 0, one is enough), and the corresponding index i, j satisfy i < j - 1. we get answer

I think it's the most tricky part!
<0,-1> can allow it to return true when the runningSum%k=0,
In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 
is not greater than 1.I think it's really beautiful and elegant here!
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // k could be negative, but is turn out okay for the code
        // m % (-n) = m % n, (a+(n*x))%x, (a%x), then n is negative, treate k as -k is okay
        // [23,2,4,6,7] -6  2 + 4 = (-6) * (-1) , n = -1
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int remainder = k != 0 ? sum % k : sum;
            
            // [3, 2, 1, 7] k = 0 never satisfy
            // [3, 0, 0] k = 0 satisfy
            if (mp.count(remainder)) {
                if (mp[remainder] < i - 1) return true;
            } else {
                mp[remainder] = i;
            }
        }
        
        return false;
    }
};