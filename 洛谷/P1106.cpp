#include <bits/stdc++.h>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    string A; cin >> A;
    int n = A.length(), k; cin >> k;
    int ans = n - k;

    stack<char> s;
    s.push(A[0]);

    int i = 1;
    for (; i < n; i++)
    {
        while(!s.empty() && A[i] < s.top() && k > 0)
        {
            s.pop();
            k--;
        }
        s.push(A[i]);
    }

    stack<char> res;

    while(!s.empty())
    {
        res.push(s.top());
        s.pop();
    }

    while(!res.empty() && res.top() == '0')  //È¥³ýÇ°µ¼Áã
    {
        res.pop();
        ans--;
    }
    if (ans <= 0) cout << 0;
    while(ans-- > 0)
    {
        cout << res.top();
        res.pop();
    }

    return 0;
}
