class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) swap(date1, date2);
        int daysOfMonth[2][13] = {
            {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // leap year
        };
        int y1 = stoi(date1.substr(0, 4)), y2 = stoi(date2.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2)), m2 = stoi(date2.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2)), d2 = stoi(date2.substr(8, 2));
        
        int res = 0;
        while (y1 < y2 || m1 < m2 || d1 < d2) {
            ++d1;
            if (d1 == daysOfMonth[isLeapYear(y1)][m1] + 1) {
                ++m1;
                d1 = 1;
            }
            if (m1 == 13) {
                ++y1;
                m1 = 1;
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