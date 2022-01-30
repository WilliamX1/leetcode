#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int m; scanf("%d", &m);

    while(m--)
    {
        int n; scanf("%d", &n);
        bool flag = true;

        stack<int> s;
        stack<int> res;

        string str;
        while(n--)
        {
            cin >> str;
            if (str == "pop")
                if (s.empty()) flag = 0;
                else s.pop();
            else if (str == "push")
            {
                int tmp;
                cin >> tmp;
                s.push(tmp);
            }
        }

        if (!flag) cout << "error";
        else
        {
            while(!s.empty())
            {
                res.push(s.top());
                s.pop();
            }
            while(!res.empty())
            {
                cout << res.top() << " ";
                res.pop();
            }
        }
        cout << endl;
    }
    return 0;
}
