class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        if (1 == month || 2 == month) {
            month += 12;
            year--;
        };
        return v[(day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7];
    };
};