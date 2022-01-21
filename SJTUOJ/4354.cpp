#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string tmp_str; cin >> tmp_str;
    string str = "";
    for (int i = 0; tmp_str[i] != '\0'; i++)
        if (tmp_str[i] > '9' || tmp_str[i] < '0')
            str = str + tmp_str[i];
    str = str + '\0';

    stack<int> s;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            s.push(i);
        else if (str[i] == ')')
        {
            int l = s.top(), r = i;
            for (int j = l; j <= (l + r) / 2; j++)
                swap(str[j], str[l + r - j]);
            s.pop();
        }
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '(' && str[i] != ')')
            cout << str[i];

    return 0;
}
