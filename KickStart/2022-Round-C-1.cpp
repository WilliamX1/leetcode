#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    string str;

    for (int i = 1; i <= T; i++)
    {
        cin >> N >> str;
        bool upper = false, lower = false, digit = false, spec = false;
        for (const char &ch : str)
        {
            if ('A' <= ch && ch <= 'Z')
                upper = true;
            else if ('a' <= ch && ch <= 'z')
                lower = true;
            else if ('0' <= ch && ch <= '9')
                digit = true;
            else
                spec = true;
        };
        if (!upper)
            str.push_back('A');
        if (!lower)
            str.push_back('a');
        if (!digit)
            str.push_back('0');
        if (!spec)
            str.push_back('#');
        if (str.size() < 7)
            str.append(string(7 - str.size(), '@'));
        printf("Case #%d: %s\n", i, str.c_str());
    };

    return 0;
}