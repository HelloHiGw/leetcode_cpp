class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int cnt1 = bitset<32>(a).count(), cnt2 = bitset<32>(b).count();
            if (cnt1 != cnt2) return cnt1 < cnt2;
            return a < b;
        });
        return arr;
    }
};