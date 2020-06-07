// class Solution {
// public:
//     int getKth(int lo, int hi, int k) {
//         map<int, set<int>> mp;
//         for (int i = lo; i <= hi; ++i) {
//             int steps = calculatePower(i);
//             mp[steps].insert(i);
//         }
//         for (auto &it : mp) {
//             if (it.second.size() >= k) {
//                 for (int val : it.second) {
//                     if (--k == 0) return val;
//                 }
//             }
//             k -= it.second.size();
//         }
//         return -1;
//     }
    
// private:
//     static bool cmp()
    
//     int calculatePower(int x) {
//         int steps = 0;
//         while (x > 1) {
//             x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
//             ++steps;
//         }
//         return steps;
//     }
// };

vector<int> v;  // put v into private, it reports error for cmp
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        v.resize(hi + 1);
        for (int i = lo; i <= hi; ++i) {
            v[i] = (calculatePower(i));
        }
        vector<int> sorted(hi - lo + 1);
        iota(sorted.begin(), sorted.end(), lo);
        nth_element(sorted.begin(), sorted.begin() + k - 1, sorted.end(), cmp);
        return sorted[k - 1];
    }
    
private:
    static bool cmp(int i, int j) {
        if (v[i] != v[j]) return v[i] < v[j];
        return i < j;
    }
    
    int calculatePower(int x) {
        int steps = 0;
        while (x > 1) {
            x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
            ++steps;
        }
        return steps;
    }
};