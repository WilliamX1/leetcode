#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int type, val;

        stack<int> s; //1
        queue<int> q; //2

        int res = 0;
        while(n--)
        {
            cin >> type >> val;
            if (!res)
            {
                if (type == 1)
                {
                    s.push(val);
                    q.push(val);
                }
                else if (type == 2)
                {
                    if (s.top() != val)
                        res = 2;
                    else s.pop();
                    if (q.front() != val)
                        res = 1;
                    else q.pop();
                }
            }
        }

        if (res == 1) cout << "Stack\n";
        else if (res == 2) cout << "Queue\n";
    }
    return 0;
}
