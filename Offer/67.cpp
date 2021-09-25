class Solution {
public:
    int strToInt(string str) {
        int len = str.size();
        int idx = 0, sign = 1;
        int64_t res = 0;
        while (idx < len && str[idx] == ' ') idx++; // 丢弃前导空格
        if (idx < len && (str[idx] == '-' || str[idx] == '+')) sign = str[idx++] == '-' ? -1 : 1;

        while (idx < len && '0' <= str[idx] && str[idx] <= '9') {
            res = res * 10 + str[idx++] - '0';
            if (sign * res > INT32_MAX) {
                res = INT32_MAX;
                break;
            } else if (sign * res < INT32_MIN) {
                res = INT32_MIN;
                break;
            };
        };
        return sign * res;
    }
};