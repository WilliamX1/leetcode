class Solution {
public:
    string makeFancyString(string s) {
        int cur_num = 0;
        char cur_ch = '/';
        string ans = "";
        for (auto ch : s)
            if (ch == cur_ch)
            {
                if (cur_num < 2)
                {
                    cur_num++;
                    ans += ch;
                }
            } else {
                cur_ch = ch;
                cur_num = 1;
                ans += ch;
            };
        return ans;
    }
};