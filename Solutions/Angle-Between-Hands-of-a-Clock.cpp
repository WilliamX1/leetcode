class Solution {
public:
    double angleClock(int hour, int minutes) {
        double HH = 30 * double (hour % 12) + (double) minutes * 30 / 60;
        double mm = (double) minutes * 360 / 60;
        double ans = abs(HH - mm);
        return ans > 180 ? 360 - ans : ans;
    }
};