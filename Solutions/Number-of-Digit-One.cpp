class Solution {
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        int len = str.size(), tot = 0;
        for (int i = 0; i < len; i++) {
            tot += i > 0 ? stol(str.substr(0, i)) * pow(10, len - i - 1) : 0;
            if (str[i] == '1') {
                tot += i < len - 1 ? stol(str.substr(i + 1)) + 1 : 1;
            } else if (str[i] > '1') {
                tot += pow(10, len - i - 1);
            };
        };
        return tot;
    }
};