#include <iostream>
#include <stack>
using namespace std;

int A[1010];

int main()
{
    int T; cin >> T;
    int N, M;
    int A_xb;
    bool flag;

    for (int i = 1; i <= T; i++)
    {
        cin >> N >> M;
        for (int j = 1; j <= N; j++)
            cin >> A[j];

        stack<int> q;

        flag = true;
        A_xb = 1;
        for (int k = 0; k < N; k++)
        {
            if (k == A[A_xb])
                A_xb++;
            else
            {
                while (!q.empty() && q.top() == A[A_xb])
                {
                    A_xb++;
                    q.pop();
                }
                if (q.size() < M)
                    q.push(k);
                else {flag = false; break;};
            }
        }
        while (!q.empty() && q.top() == A[A_xb])
        {
            A_xb++;
            q.pop();
        }
        if (flag && q.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
