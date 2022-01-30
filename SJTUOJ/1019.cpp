#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T; cin >> T;

    string str;

    for (int i = 0; i < T; i++)
    {
        stack<char> q;

        cin >> str;

        for (int j = 0; str[j] != '\0'; ++j)
        {
            if (q.empty()) q.push(str[j]);
            else
                if (q.top() == '(' && str[j] == ')')
                    q.pop();
                else
                    q.push(str[j]);
        }
        if (q.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
