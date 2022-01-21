#include <iostream>
#include <stack>
using namespace std;

int to(string A)
{
    if (A == "begin") return 0;
    if (A == "end") return 1;
    if (A == "if") return 2;
    if (A == "then") return 3;
    if (A == "else") return 4;
}
int main()
{
    string tmp;
    stack<int> q;

    int N; cin >> N;
    int ch;
    bool flag = true;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        ch = to(tmp);

        if (q.empty()) q.push(ch);
        else
        {
            if (ch == 0)
            {
                if (q.top() == 2) {flag = false; break;}
                q.push(ch);
            }
            else if (ch == 1)
            {
                if (!q.empty() && q.top() == 3) {q.pop(); q.pop();}
                if (!q.empty() && q.top() == 0) q.pop();
                else {flag = false; break;}
            }
            else if (ch == 2)
                q.push(ch);
            else if (ch == 3)
            {
                if (q.top() != 2) {flag = false; break;};
                q.push(ch);
            }
            else if (ch == 4)
                if (q.top() == 3) {q.pop(); q.pop();}
                else {flag = false;break;}
        }
    }
    while(!q.empty() && q.top() == 3)
    {
        q.pop();
        if (!q.empty() && q.top() == 2)
            q.pop();
        else{
            flag = false;
            break;
        }
    }

    if (flag && q.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
