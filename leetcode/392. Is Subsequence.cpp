// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int i = 0;
//         for (int j = 0; j < t.size() && i < s.size(); ++j) {
//             if (t[j] == s[i]) ++i;
//         }
//         return i == s.size();
//     }
// };


class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> char2pos;
        for (int i = 0; i < t.size(); ++i) {
            char2pos[t[i]].push_back(i);
        }
        int pre = -1;
        for (char ch : s) {
            int pos = upperBound(char2pos[ch], pre);
            if (pos == char2pos[ch].size()) return false;  // pre is bigger than all the index with ch, false, e.g find abc in bbaacc
            pre = char2pos[ch][pos];
            // auto pos = upper_bound(char2pos[ch].begin(), char2pos[ch].end(), pre);
            // if (pos == char2pos[ch].end()) return false;
            // pre = *pos;
        }
        return true;
    }

private:
    int upperBound(vector<int>& v, int target) {
        int low = 0, high = v.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (v[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

/*
record the indexes for each character in t, if s[i] matches t[j], 
then s[i+1] should match a character in t with index bigger than j. 
This can be reduced to find the first element larger than a value in 
an sorted array (find upper bound), which can be achieved using binary search.

find abc in bababc
map: a 1 3  b 0 2 4    c 5

pre = -1, pos = 0, it denotes pre index is smaller than all index with value 'a', ok
and pre is set as m[a][pos] = 1, it denotes the matched 'a' is at index 1

pre = 0, pos = 1, it denotes index with value 'b' has element bigger than pre, ok
and pre is set as m[b][pos] = 2, it denotes the matched 'b' is at index 2
*/