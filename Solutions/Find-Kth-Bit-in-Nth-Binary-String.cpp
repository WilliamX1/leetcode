class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i <= n; i++) {
            string s_rev = s;
            for (int i = 0; i < s_rev.length(); i++)
                if (s_rev[i] == '0') s_rev[i] = '1';
                else s_rev[i] = '0';
            reverse(s_rev.begin(), s_rev.end());
            s = s + "1" + s_rev;
        };
        return s[k - 1];
    }
};