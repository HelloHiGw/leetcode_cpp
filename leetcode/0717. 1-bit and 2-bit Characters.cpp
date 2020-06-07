class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.back() == 1) return false;
        int count = 0;
        for (int i = bits.size() - 2; i >= 0 && bits[i] == 1; --i) {
            ++count;
        }
        return count % 2 == 0;
    }
};