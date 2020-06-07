class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        set<int> st;
        int sumA = 0, sumB = 0;
        for (int num : A) {
            sumA += num;
        }
        for (int num : B) {
            st.insert(num);
            sumB += num;
        }
        int diff = (sumB - sumA) / 2;
        for (int num : A) {
            if (st.find(num + diff) != st.end()) return {num, num + diff};
        }
        return {};
    }
};