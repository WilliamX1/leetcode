#include <string>

using namespace std;

class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        string ans = "";
        int len1 = num1.size(), len2 = num2.size(), len = len1 + len2 + 1;
        for (int i = 0; i < len; i++)
            ans = ans + '0';

        for (int i = len1 - 1; i >= 0; i--)
            for (int j = len2 - 1; j >= 0; j--)
            {
                int idx = (len1 - i) + (len2 - j) - 2;
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int ab = a * b; // 组成 "ab" 形式的数
                a = ab / 10;
                b = ab % 10 + (ans[idx] - '0');
                a += b / 10;
                b %= 10;
                ans[idx] = char(b + '0');

                while (a > 0)
                {
                    a += ans[++idx] - '0';
                    ans[idx] = char(a % 10 + '0');
                    a /= 10;
                };
            };
        while (--len >= 0 && ans[len] == '0')
            ;
        string str = ans.substr(0, ++len);
        reverse(str.begin(), str.end());
        return str;
    }
};