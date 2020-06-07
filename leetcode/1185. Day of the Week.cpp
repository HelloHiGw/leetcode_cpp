class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> daysOfWeek{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        vector<int> daysOfMonth{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += 365;
            if (isLeap(y)) days += 1;
        }
        for (int m = 1; m < month; ++m) {
            days += daysOfMonth[m];
            if (m == 2 && isLeap(year)) days += 1;
        }
        days += day - 1;  // days from 1971.1.1 so have to -1
        days = (days + 4) % 7;  // 1971.1.1 is Friday
        return daysOfWeek[days];
    }
    
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};