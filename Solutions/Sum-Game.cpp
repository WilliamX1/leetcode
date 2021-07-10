class Solution {
public:
    bool judge(int L_kong, int R_kong, int sum) {
        int ans = 0;
        bool who = 0;
        while (R_kong-- > 0) {
            if (who) ans += 9;
            else ans += 0;
            who = !who;
        };
        while (L_kong-- > 0) {
            if (who) ans -= 0;
            else ans -= 9;
            who = !who;
        };
        return sum + ans > 0;
    };
    bool sumGame(string num) {
        int len = num.size();
        int L_sum = 0, L_kong = 0, R_sum = 0, R_kong = 0;
        int i = 0;
        for (; i < len / 2; i++)
            if ('0' <= num[i] && num[i] <= '9') L_sum += num[i] - '0';
            else L_kong++;
        for (; i < len; i++)
            if ('0' <= num[i] && num[i] <= '9') R_sum += num[i] - '0';
            else R_kong++;

        /* Alice 最后一手 */
        if ((L_kong + R_kong) & 1) return true;
        else return judge(L_kong, R_kong, R_sum - L_sum) || judge(R_kong, L_kong, L_sum - R_sum);
    }
};