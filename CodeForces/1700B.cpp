#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

string substract(string num1, string num2)
{
    string ans;
    int n1 = num1.size(), n2 = num2.size(), more = 0;
    for (int i = 0; i < n2; i++)
    {
        int cur = num1[n1 - i - 1] - more - num2[n2 - i - 1];
        if (cur >= 0)
        {
            more = 0;
            ans.push_back(cur + '0');
        }
        else
        {
            more = 1;
            ans.push_back(cur + 10 + '0');
        };
    };
    reverse(ans.begin(), ans.end());

    return ans;
};

int main()
{
    int t, len;
    string n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> len >> n;
        if (n[0] == '9')
        {
            cout << substract(string(n.size() + 1, '1'), n) << endl;
        }
        else
        {
            cout << substract(string(n.size(), '9'), n) << endl;
        };
    };

    return 0;
}