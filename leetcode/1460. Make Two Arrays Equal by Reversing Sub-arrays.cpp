/*
if two arrays have the same elements, arr can always be reversed and become target
find target[i] in arr, arr[j]. reverse arr[i] thru arr [j]. Then increment i. 

because i is monotonically increasing, and the two arrays have the same elements, for 
every target[i]

we can find its counter part in arr, and get that counter part to the same i-th 
position in target.

therefore, we only needs to check if two arrays have the same element. 
*/
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> count(1010);
        for (int i = 0; i < arr.size(); ++i) {
            ++count[arr[i]];
            --count[target[i]];
        }
        for (int i = 1; i <= 1000; ++i) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return unordered_multiset<int>(target.begin(), target.end()) == unordered_multiset<int>(arr.begin(), arr.end());
    }
};