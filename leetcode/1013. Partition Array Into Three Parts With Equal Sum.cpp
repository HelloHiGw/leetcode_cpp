class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, currSum = 0, count = 0;
        for (int num : A) {
            sum += num;
        }
        if (sum % 3 != 0) return false;
        for (int num : A) {
            currSum += num;
            if (currSum == sum / 3) {
                ++count;
                currSum = 0;
            }
        }
        return count >= 3;
    }
};