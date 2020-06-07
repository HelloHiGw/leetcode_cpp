class Solution {
public:
    int dayOfYear(string date) {
        int daysOfMonth[2][13] = {
            {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // leap year
        };
        int y = stoi(date.substr(0, 4)), m2 = stoi(date.substr(5, 2)), d2 = stoi(date.substr(8, 2));
        int m1 = 1, d1 = 0;

        int res = 0;
        while (m1 < m2 || d1 < d2) {
            ++d1;
            if (d1 == daysOfMonth[isLeapYear(y)][m1] + 1) {
                ++m1;
                d1 = 1;
            }
            ++res;
        }
        return res;
        
    }

private:
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
};