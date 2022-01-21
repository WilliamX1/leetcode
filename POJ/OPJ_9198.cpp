#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    char tmp;

    while(scanf("%c", &tmp) != EOF && tmp != '\n')
    {
        if (!s.empty())
        {
            if (tmp == '}' && s.top() == '{')
                s.pop();
            else if (tmp == ']' && s.top() == '[')
                s.pop();
            else if (tmp == ')' && s.top() == '(')
                s.pop();
            else s.push(tmp);
        }
        else s.push(tmp);
        //cout << s.top();
    }

    if (s.empty()) printf("%s", "Yes");
    else printf("%s", "No");

    return 0;
}
