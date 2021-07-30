class Solution {
public:
    int getLucky(string s, int k) {
        string ans;
        for (auto ch : s)
            ans += to_string(ch - 'a' + 1);
        int num = 0;
        while (k-- > 0) {
            num = 0;
            for (auto ch : ans)
                num += ch - '0';
            ans = to_string(num);
        };
        return num;
    }
};