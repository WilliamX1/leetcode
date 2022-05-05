class Solution {
public:
    int maxDiff(int num) {
        string num_str = to_string(num);
        string num_max = num_str, num_min = num_str;

        for (char x = '0'; x <= '9'; x++) {
            for (char y = '0'; y <= '9'; y++) {
                string tmp = num_str;
                for (char& ch : tmp) {
                    if (ch == x) {
                        ch = y;
                    };
                };
                if (tmp[0] == '0') continue;
                else {
                    num_max = max(num_max, tmp);
                    num_min = min(num_min, tmp);
                };
            };
        };

        return stol(num_max) - stol(num_min);
    }
};